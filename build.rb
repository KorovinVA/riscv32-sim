require 'fileutils'

# llvm build
puts "Building LLVM..."
LLVM_BUILD_DIR = "llvm-project/build"
unless File.directory? LLVM_BUILD_DIR
  FileUtils.mkdir(LLVM_BUILD_DIR)
  Dir.chdir(LLVM_BUILD_DIR) do
    system("cmake ../llvm -DCMAKE_BUILD_TYPE=Release -G Ninja")
  end
end

Dir.chdir(LLVM_BUILD_DIR) do
  status = system("cmake --build . --target Kaleidoscope --config Release --verbose")
  unless status
    puts "LLVM build failed!"
  end
end

# google-bench build


# riscv-sim build
puts "Building RISCV32..."
RISCV_SIM_DIR = "build"
unless File.directory? RISCV_SIM_DIR
  FileUtils.mkdir(RISCV_SIM_DIR)
  Dir.chdir(RISCV_SIM_DIR) do
    system("cmake .. -DCMAKE_BUILD_TYPE=Release -G Ninja")
  end
end

Dir.chdir(RISCV_SIM_DIR) do
  status = system("cmake --build . --config Release")
  unless status
    puts "RISCV32 build failed!"
  end
end

