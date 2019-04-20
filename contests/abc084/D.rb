require 'prime'

MAX_R = 100000

as = Array.new(MAX_R+1, 0)

1.upto(MAX_R + 1) do |i|
  as[i] = as[i-1] + ((Prime.prime?(i) && Prime.prime?((i + 1) / 2)) ? 1 : 0)
end

Q = gets.chomp.to_i

Q.times do
  l, r = gets.chomp.split.map(&:to_i)

  puts (as[r] - as[l-1])
end
