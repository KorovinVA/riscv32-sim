require 'fileutils'

# llvm build
puts "Building LLVM..."
LLVM_BUILD_DIR = "llvm-project/build"
unless File.directory? LLVM_BUILD_DIR
  FileUtils.mkdir(LLVM_BUILD_DIR)
  Dir.chdir(LLVM_BUILD_DIR) do
    status = system("cmake ../llvm -DCMAKE_BUILD_TYPE=Release -G Ninja")
    unless status
      FileUtils.rm_rf LLVM_BUILD_DIR
      puts "LLVM config failed!"
    end
  end
end

Dir.chdir(LLVM_BUILD_DIR) do
  status = system("cmake --build . --target Kaleidoscope --config Release --verbose")
  unless status
    puts "LLVM build failed!"
  end
end

# google-bench build
puts "Building GOOGLE-BENCH..."
BENCH_BUILD_DIR = "benchmark/build"
unless File.directory? BENCH_BUILD_DIR
  FileUtils.mkdir(BENCH_BUILD_DIR)
  Dir.chdir(BENCH_BUILD_DIR) do
    status = system("cmake .. -DCMAKE_BUILD_TYPE=Release -G Ninja")
    unless status
      FileUtils.rm_rf BENCH_BUILD_DIR
      puts "Google-bench config failed!"
    end
  end
end

Dir.chdir(BENCH_BUILD_DIR) do
  status = system("cmake --build . --config Release")
  unless status
    puts "Google-bench build failed!"
  end
end


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


# set project env variable
puts "Before running project you must set the following variable. Please run:"
puts "export RISCV32I_SIM=#{__dir__}"
Dir.chdir(__dir__) do
  unless File.directory? "output"
    FileUtils.mkdir "output"
  end
end
