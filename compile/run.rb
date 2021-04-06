BENCHMARK_INCLUDE = !REPLACE_BENCHMARK_INCLUDE! 
BENCHMARK_LIB     = !REPLACE_BENCHMARK_LIB!

def exec(cmd)
  puts cmd
  success = system(cmd)
  unless success
    puts "Command wasn't successful!"
    exit
  end
end

Dir.chdir(__dir__) do
  puts "Compiling..."
  exec("llc -filetype=obj ir.ll")
  exec("g++ -isystem #{BENCHMARK_INCLUDE} -c main.cpp")
  exec("g++ -L #{BENCHMARK_LIB} -l benchmark_main -l benchmark -l pthread -l rt  main.o ir.o -o out")

  puts "Running test..."
  exec("./out")
  puts "Success!"
end

