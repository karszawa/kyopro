rc = 0
bc = 0

gets

gets.chomp.split('').map do |c|
  if c == 'R'
    rc += 1
  else
    bc += 1
  end
end

if rc > bc
  puts 'Yes'
else
  puts 'No'
end
