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
#include "macro.h"

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
    Converter(const std::string& outputDir,
              std::vector<ISA::Instruction>& instBuff,
	      uint8_t* data,
	      uint32_t dataSize, 
	      uint32_t entryPoint);
    void translate();
private:
    void createFunctions();
    llvm::Function* createFunction(const std::string& name);
    void createJumpTable(FINfo* f, uint32_t startPc, uint32_t endPc);
    void createBranch(uint32_t jump, FINfo* func, uint32_t passBy = 0, llvm::Value* cond = nullptr);

    void emitInst(ISA::Instruction inst, FINfo* currentF);
    int getInstructionIdx(uint32_t pc) const;

    void storeRegValue(llvm::Value* dst, uint32_t rd);
    llvm::Value* getRegValue(uint32_t n);
    llvm::Value* getConstant(uint32_t imm);

    std::vector<ISA::Instruction> insts;
    const std::string output;

    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;

    llvm::FunctionType* fType;
    llvm::Function* entryF;
    std::map<uint32_t, FINfo> fmap;
    uint32_t entryP;

    llvm::GlobalVariable* regFile;
};

#endif //CONVERTER_H
