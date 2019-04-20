a, b = gets.chomp.split.map(&:to_i)

puts [(a + 1) * b, a * (b + 1)].max
