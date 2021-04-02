#ifndef CONVERTER_H
#define CONVERTER_H

#pragma warning(push, 0)
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Constants.h>
#pragma warning(pop)

#include "instruction.h"

class Converter
{
    struct BBInfo
    {
        uint32_t startPc = 0;
        uint32_t endPc = 0;

        bool isPseudoJump = false;
        llvm::BasicBlock* block = nullptr;
    };
    struct FINfo
    {
        llvm::Function* function;
        std::list<BBInfo> bbinfo;
    };
public:
    Converter(std::vector<ISA::Instruction>& instBuff);
	void translate();
private:
    void createFunctions();
    void createJumpTable(FINfo* f, uint32_t startPc, uint32_t endPc);
    void emitInst(ISA::Instruction inst, FINfo* currentF);

    // helpers
    void createBranch(uint32_t jump, FINfo* func, uint32_t passBy = 0, llvm::Value* cond = nullptr);
    int getInstructionIdx(uint32_t pc) const;
    llvm::Function* createFunction(const std::string& name);
    void storeRegValue(llvm::Value* dst, uint32_t rd);
    llvm::Value* getRegValue(uint32_t n);
    llvm::Value* getConstant(uint32_t imm);

    const static int REGISTER_NUM = 32;
    std::vector<ISA::Instruction> insts;

    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;

    llvm::FunctionType* fType = nullptr;
    std::map<uint32_t, FINfo> fmap;

    llvm::Value* buffer;
    llvm::GlobalVariable* regFile;
};

#endif //CONVERTER_H