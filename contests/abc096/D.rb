require 'prime'

N = gets.chomp.to_i
i = 0

55555.times do |n|
  next unless Prime.prime?(n)
  next unless n >= 10
  next unless n % 5 == 1

  puts n

  break if (i += 1) >= N
end
