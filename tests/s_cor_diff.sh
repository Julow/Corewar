for f in *.s; do
	echo "$f:"
	DEST="${f%%.s}.cor"
	/sgoinfre/goinfre/corewar/asm "$f"
	if [[ ! -f "$DEST" ]]; then
		echo "	ERROR zaz failed"
	else
		mv "$DEST" a
		../asm "$f"
		if [[ ! -f "$DEST" ]]; then
			echo "	ERROR we failed"
		else
			mv "$DEST" b
			if ! diff a b; then
				exit
			else
				read
			fi
		fi
	fi
done
