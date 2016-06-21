.name "jswag"
.comment "- \"lvl 19.98%\""

		sti			r1, %:live, %1
live:	live		%-559038737
		# lfork		%2048

# loop_init:
# 	sti r1, %:loop, %1
# 	ldi			%:loop, %0, r4
# 	ldi			%:loop, %4, r5
# 	ldi			%:loop, %8, r6
# 	ldi			%:loop, %12, r7

# loop:
# 	live		%-559038737
# 	st			r4, -500
# 	st			r5, -501
# 	st			r6, -502
# 	st			r7, -503
# 	zjmp		%:loop
