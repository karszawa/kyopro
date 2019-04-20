A, B, C = gets.chomp.split.map(&:to_i)

if A == B && B == C
  puts 'Yes'
else
  puts 'No'
end
