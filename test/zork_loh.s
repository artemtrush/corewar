.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		# and r1, %0, r1 # if (*r1 == 0) carry = 1;
		sti r1, %101, %0

live:	live %1
		zjmp %:live # if (carry == 1)
