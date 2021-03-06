INCLUDE_FLAGS += -I$(O_DIR)/_public
LINK_FLAGS += -lcurses
MAINS += asm corewar disass
OBJ_DIR_TREE += $(O_DIR)/srcs/vm_loader/ $(O_DIR)/srcs/vm_exec/operations/ \
	$(O_DIR)/srcs/vm_exec/ $(O_DIR)/srcs/vm/ $(O_DIR)/srcs/ui/ui_panel/ \
	$(O_DIR)/srcs/ui/ui_log/ $(O_DIR)/srcs/ui/ui_arena/ \
	$(O_DIR)/srcs/ui/listeners/ $(O_DIR)/srcs/ui/ $(O_DIR)/srcs/instr_loader/ \
	$(O_DIR)/srcs/disass/ $(O_DIR)/srcs/debug_ui/ $(O_DIR)/srcs/corewar_main/ \
	$(O_DIR)/srcs/corewar_config/ $(O_DIR)/srcs/cor_loader/ \
	$(O_DIR)/srcs/asm_parser/ $(O_DIR)/srcs/asm_data/ \
	$(O_DIR)/srcs/asm_bytecode/ $(O_DIR)/srcs/asm/ $(O_DIR)/srcs/ \
	$(O_DIR)/libft/get_next_line/ $(O_DIR)/libft/ft_vector/ \
	$(O_DIR)/libft/ft_tokenizer/ $(O_DIR)/libft/ft_set/ \
	$(O_DIR)/libft/ft_printf/formats/ $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_path/ $(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_list/ \
	$(O_DIR)/libft/ft_in/ $(O_DIR)/libft/ft_hmap/ $(O_DIR)/libft/ft_file_out/ \
	$(O_DIR)/libft/ft_file_in/ $(O_DIR)/libft/ft_file/ $(O_DIR)/libft/ft_dstr/ \
	$(O_DIR)/libft/ft_bst/ $(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ft_argv/ \
	$(O_DIR)/libft/ $(O_DIR)/_public/ft/ $(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/srcs/asm/compile.o $(O_DIR)/srcs/asm/debug.o \
	$(O_DIR)/srcs/asm/main.o $(O_DIR)/srcs/asm/parse_params.o \
	$(O_DIR)/srcs/asm_bytecode/asm_bytecode.o \
	$(O_DIR)/srcs/asm_bytecode/asm_header.o \
	$(O_DIR)/srcs/asm_bytecode/bcode_gen.o \
	$(O_DIR)/srcs/asm_bytecode/bcode_gen_args.o \
	$(O_DIR)/srcs/asm_bytecode/labels_ref.o $(O_DIR)/srcs/asm_bytecode/utils.o \
	$(O_DIR)/srcs/asm_data/asm_destroy.o \
	$(O_DIR)/srcs/asm_data/asm_label_cmp.o \
	$(O_DIR)/srcs/asm_parser/check_instr.o \
	$(O_DIR)/srcs/asm_parser/check_labels.o \
	$(O_DIR)/srcs/asm_parser/parse_asm.o \
	$(O_DIR)/srcs/asm_parser/parse_comment.o \
	$(O_DIR)/srcs/asm_parser/parse_instr.o \
	$(O_DIR)/srcs/asm_parser/parse_instr_arg.o \
	$(O_DIR)/srcs/asm_parser/parse_label_or_instr.o \
	$(O_DIR)/srcs/asm_parser/parse_string.o $(O_DIR)/srcs/asm_parser/utils.o \
	$(O_DIR)/srcs/cor_loader/cor_destroy.o $(O_DIR)/srcs/cor_loader/load_cor.o \
	$(O_DIR)/srcs/corewar_main/dump_loop.o \
	$(O_DIR)/srcs/corewar_main/exec_loop.o $(O_DIR)/srcs/corewar_main/main.o \
	$(O_DIR)/srcs/corewar_main/parse_argv.o \
	$(O_DIR)/srcs/corewar_main/parse_argv_opt.o \
	$(O_DIR)/srcs/corewar_main/parse_tools.o $(O_DIR)/srcs/corewar_config/op.o \
	$(O_DIR)/srcs/debug_ui/debug_dump.o $(O_DIR)/srcs/debug_ui/debug_loop.o \
	$(O_DIR)/srcs/disass/main.o $(O_DIR)/srcs/disass/print_cor.o \
	$(O_DIR)/libft/ft_argv/arg.o $(O_DIR)/libft/ft_argv/opt.o \
	$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_base/ft_assert.o \
	$(O_DIR)/libft/ft_base/ft_atoib.o $(O_DIR)/libft/ft_base/ft_bitset.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_base/ft_is.o \
	$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_memmove.o \
	$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_memset.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_memswap.o \
	$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_nanoclock.o \
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_base/ft_subfind.o $(O_DIR)/libft/ft_base/ft_subnext.o \
	$(O_DIR)/libft/ft_base/ft_subto.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_base/ft_wstrconv.o \
	$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_bst/bst_balance.o $(O_DIR)/libft/ft_bst/ft_bst_destroy.o \
	$(O_DIR)/libft/ft_bst/ft_bstdel.o $(O_DIR)/libft/ft_bst/ft_bstget.o \
	$(O_DIR)/libft/ft_bst/ft_bstgetall.o $(O_DIR)/libft/ft_bst/ft_bstiter.o \
	$(O_DIR)/libft/ft_bst/ft_bstmax.o $(O_DIR)/libft/ft_bst/ft_bstmin.o \
	$(O_DIR)/libft/ft_bst/ft_bstput.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_file/open.o \
	$(O_DIR)/libft/ft_file_in/file_in.o \
	$(O_DIR)/libft/ft_file_in/file_in_open.o \
	$(O_DIR)/libft/ft_file_out/file_out.o \
	$(O_DIR)/libft/get_next_line/get_next_line.o \
	$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_in/ft_in_refresh.o \
	$(O_DIR)/libft/ft_in/ft_read.o $(O_DIR)/libft/ft_in/ft_readto.o \
	$(O_DIR)/libft/ft_list/ft_listadd.o $(O_DIR)/libft/ft_list/ft_listremove.o \
	$(O_DIR)/libft/ft_list/ft_listsort.o $(O_DIR)/libft/ft_out/ft_putchar.o \
	$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
	$(O_DIR)/libft/ft_out/ft_putpad.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_out/ft_putsub.o $(O_DIR)/libft/ft_out/ft_putuint.o \
	$(O_DIR)/libft/ft_out/ft_str_out.o $(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_path/path.o $(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_printf/exec_format.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/libft/ft_printf/formats/str.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
	$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
	$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o \
	$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
	$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
	$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o \
	$(O_DIR)/libft/ft_tokenizer/ft_token_map.o \
	$(O_DIR)/libft/ft_tokenizer/ft_tokenize.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o $(O_DIR)/libft/ft_vector/ft_vpush.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/libft/ft_vector/ft_vspan.o \
	$(O_DIR)/srcs/instr_loader/load_instr.o $(O_DIR)/srcs/ui/key_handler.o \
	$(O_DIR)/srcs/ui/listeners/on_aff.o $(O_DIR)/srcs/ui/listeners/on_write.o \
	$(O_DIR)/srcs/ui/ui.o $(O_DIR)/srcs/ui/ui_arena/arena_update.o \
	$(O_DIR)/srcs/ui/ui_arena/w_arena.o $(O_DIR)/srcs/ui/ui_init.o \
	$(O_DIR)/srcs/ui/ui_log/w_log.o $(O_DIR)/srcs/ui/ui_panel/w_panel.o \
	$(O_DIR)/srcs/vm/vm_access.o $(O_DIR)/srcs/vm/vm_destroy.o \
	$(O_DIR)/srcs/vm/vm_start.o $(O_DIR)/srcs/vm_exec/exec_op.o \
	$(O_DIR)/srcs/vm_exec/get_values.o $(O_DIR)/srcs/vm_exec/operations/add.o \
	$(O_DIR)/srcs/vm_exec/operations/aff.o \
	$(O_DIR)/srcs/vm_exec/operations/and.o \
	$(O_DIR)/srcs/vm_exec/operations/fork.o \
	$(O_DIR)/srcs/vm_exec/operations/ld.o \
	$(O_DIR)/srcs/vm_exec/operations/ldi.o \
	$(O_DIR)/srcs/vm_exec/operations/live.o \
	$(O_DIR)/srcs/vm_exec/operations/lld.o \
	$(O_DIR)/srcs/vm_exec/operations/lldi.o \
	$(O_DIR)/srcs/vm_exec/operations/or.o \
	$(O_DIR)/srcs/vm_exec/operations/st.o \
	$(O_DIR)/srcs/vm_exec/operations/sti.o \
	$(O_DIR)/srcs/vm_exec/operations/sub.o \
	$(O_DIR)/srcs/vm_exec/operations/xor.o \
	$(O_DIR)/srcs/vm_exec/operations/zjmp.o $(O_DIR)/srcs/vm_exec/vm_check.o \
	$(O_DIR)/srcs/vm_exec/vm_exec.o $(O_DIR)/srcs/vm_loader/load_vm.o \
	$(O_DIR)/srcs/vm_loader/misc.o
PUBLIC_LINKS += $(O_DIR)/_public/asm_bytecode.h $(O_DIR)/_public/asm_data.h \
	$(O_DIR)/_public/asm_parser.h $(O_DIR)/_public/cor_loader.h \
	$(O_DIR)/_public/op.h $(O_DIR)/_public/debug_ui.h \
	$(O_DIR)/_public/ft/argv.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/libft.h \
	$(O_DIR)/_public/ft/ft_bst.h $(O_DIR)/_public/ft/ft_dstr.h \
	$(O_DIR)/_public/ft/file.h $(O_DIR)/_public/ft/file_in.h \
	$(O_DIR)/_public/ft/file_out.h $(O_DIR)/_public/ft/get_next_line.h \
	$(O_DIR)/_public/ft/ft_hmap.h $(O_DIR)/_public/ft/ft_in.h \
	$(O_DIR)/_public/ft/ft_list.h $(O_DIR)/_public/ft/ft_out.h \
	$(O_DIR)/_public/ft/ft_str_out.h $(O_DIR)/_public/ft/path.h \
	$(O_DIR)/_public/ft/ft_printf.h $(O_DIR)/_public/ft/ft_vprintf.h \
	$(O_DIR)/_public/ft/set.h $(O_DIR)/_public/ft/tokenizer.h \
	$(O_DIR)/_public/ft/ft_vector.h $(O_DIR)/_public/instr.h \
	$(O_DIR)/_public/instr_loader.h $(O_DIR)/_public/ui.h \
	$(O_DIR)/_public/utils.h $(O_DIR)/_public/process.h $(O_DIR)/_public/vm.h \
	$(O_DIR)/_public/player.h $(O_DIR)/_public/vm_exec.h \
	$(O_DIR)/_public/vm_loader.h

asm:$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_in/ft_read.o $(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o \
	$(O_DIR)/srcs/asm_parser/parse_label_or_instr.o \
	$(O_DIR)/libft/ft_out/ft_write_char.o $(O_DIR)/libft/ft_set/insert.o \
	$(O_DIR)/srcs/asm_parser/parse_asm.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_printf/ft_logf.o $(O_DIR)/srcs/asm/parse_params.o \
	$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/ft_bitset.o $(O_DIR)/libft/ft_base/ft_getenv.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o $(O_DIR)/libft/ft_set/first.o \
	$(O_DIR)/srcs/asm_bytecode/bcode_gen_args.o \
	$(O_DIR)/libft/ft_bst/ft_bstdel.o $(O_DIR)/libft/ft_file_out/file_out.o \
	$(O_DIR)/srcs/asm_bytecode/asm_bytecode.o \
	$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_bst/ft_bstget.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o $(O_DIR)/srcs/asm_data/asm_destroy.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/srcs/corewar_config/op.o \
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_path/path.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o $(O_DIR)/libft/ft_hmap/ft_djb2.o \
	$(O_DIR)/libft/ft_file/open.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/libft/ft_bst/ft_bstmax.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_argv/opt.o $(O_DIR)/srcs/asm_data/asm_label_cmp.o \
	$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/srcs/asm_bytecode/bcode_gen.o \
	$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_vector/ft_vpush.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o $(O_DIR)/libft/ft_file_in/file_in.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_bst/ft_bstgetall.o \
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/srcs/asm/compile.o \
	$(O_DIR)/srcs/asm_parser/parse_comment.o $(O_DIR)/srcs/asm/debug.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapput.o $(O_DIR)/libft/ft_list/ft_listadd.o \
	$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_argv/arg.o $(O_DIR)/srcs/asm_bytecode/utils.o \
	$(O_DIR)/srcs/asm_parser/parse_instr_arg.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/srcs/asm/main.o \
	$(O_DIR)/libft/ft_base/ft_escape.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/libft/ft_bst/bst_balance.o $(O_DIR)/srcs/asm_parser/check_instr.o \
	$(O_DIR)/libft/ft_set/utils.o $(O_DIR)/libft/ft_in/ft_readto.o \
	$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_in/ft_in_refresh.o \
	$(O_DIR)/libft/ft_hmap/ft_hmaprem.o $(O_DIR)/libft/ft_base/ft_nanoclock.o \
	$(O_DIR)/libft/ft_bst/ft_bstmin.o $(O_DIR)/srcs/asm_parser/check_labels.o \
	$(O_DIR)/libft/ft_set/get.o $(O_DIR)/libft/ft_out/ft_putint.o \
	$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_file_in/file_in_open.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_list/ft_listsort.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_base/ft_assert.o \
	$(O_DIR)/libft/ft_set/iter.o $(O_DIR)/libft/ft_printf/ft_putf.o \
	$(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_vector/ft_vspan.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_out/ft_putsub.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_out/ft_putchar.o \
	$(O_DIR)/libft/ft_base/ft_subto.o $(O_DIR)/srcs/asm_bytecode/asm_header.o \
	$(O_DIR)/libft/ft_base/ft_memset.o \
	$(O_DIR)/libft/ft_tokenizer/ft_token_map.o \
	$(O_DIR)/libft/ft_tokenizer/ft_tokenize.o \
	$(O_DIR)/libft/ft_base/ft_memcmp.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/srcs/asm_parser/parse_instr.o \
	$(O_DIR)/libft/ft_bst/ft_bstput.o $(O_DIR)/libft/ft_printf/exec_format.o \
	$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/srcs/asm_bytecode/labels_ref.o \
	$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_bst/ft_bstiter.o \
	$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o \
	$(O_DIR)/libft/ft_bst/ft_bst_destroy.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o \
	$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_out/ft_putpad.o \
	$(O_DIR)/libft/ft_list/ft_listremove.o $(O_DIR)/libft/ft_out/ft_putuint.o \
	$(O_DIR)/srcs/asm_parser/utils.o $(O_DIR)/srcs/asm_parser/parse_string.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_str_out.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o

corewar: $(O_DIR)/srcs/ui/listeners/on_write.o \
	$(O_DIR)/srcs/corewar_main/dump_loop.o $(O_DIR)/libft/ft_base/ft_subnext.o \
	$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_dstr/ft_dstrspan.o \
	$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/srcs/debug_ui/debug_loop.o \
	$(O_DIR)/srcs/vm_exec/operations/sti.o $(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o $(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/srcs/vm/vm_start.o $(O_DIR)/libft/ft_out/ft_putsub.o \
	$(O_DIR)/srcs/vm_exec/vm_check.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_printf/ft_logf.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/srcs/debug_ui/debug_dump.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/ft_bitset.o $(O_DIR)/libft/ft_base/ft_getenv.o \
	$(O_DIR)/srcs/vm/vm_access.o $(O_DIR)/srcs/corewar_main/parse_argv.o \
	$(O_DIR)/srcs/corewar_main/parse_tools.o $(O_DIR)/srcs/ui/ui.o \
	$(O_DIR)/srcs/vm_loader/misc.o $(O_DIR)/srcs/vm_exec/operations/or.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/srcs/vm_exec/operations/lld.o \
	$(O_DIR)/srcs/ui/ui_arena/arena_update.o \
	$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/srcs/corewar_main/parse_argv_opt.o \
	$(O_DIR)/srcs/cor_loader/load_cor.o $(O_DIR)/libft/ft_base/ft_strlen.o \
	$(O_DIR)/srcs/corewar_config/op.o $(O_DIR)/srcs/vm_exec/operations/sub.o \
	$(O_DIR)/srcs/corewar_main/exec_loop.o \
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/srcs/vm_exec/operations/fork.o $(O_DIR)/libft/ft_out/ft_putchar.o \
	$(O_DIR)/srcs/vm_exec/operations/zjmp.o $(O_DIR)/srcs/ui/ui_log/w_log.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/srcs/vm_exec/operations/lldi.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_base/ft_nanoclock.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/srcs/vm_exec/operations/ld.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_argv/opt.o $(O_DIR)/libft/ft_base/ft_memmove.o \
	$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_vector/ft_vpush.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o \
	$(O_DIR)/srcs/vm_exec/operations/live.o \
	$(O_DIR)/srcs/ui/ui_arena/w_arena.o $(O_DIR)/libft/ft_base/ft_rand.o \
	$(O_DIR)/libft/get_next_line/get_next_line.o \
	$(O_DIR)/libft/ft_list/ft_listadd.o $(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_argv/arg.o $(O_DIR)/libft/ft_vector/ft_vreserve.o \
	$(O_DIR)/srcs/vm_exec/exec_op.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/srcs/vm_exec/operations/aff.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/srcs/corewar_main/main.o $(O_DIR)/libft/ft_file/open.o \
	$(O_DIR)/srcs/vm_exec/operations/and.o $(O_DIR)/srcs/vm_exec/vm_exec.o \
	$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_printf/ft_out.o \
	$(O_DIR)/srcs/vm_exec/operations/ldi.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/srcs/ui/ui_panel/w_panel.o \
	$(O_DIR)/srcs/ui/listeners/on_aff.o $(O_DIR)/libft/ft_printf/ft_aprintf.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_list/ft_listsort.o \
	$(O_DIR)/srcs/vm_exec/operations/xor.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_base/ft_assert.o \
	$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_vector/ft_vspan.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_is.o \
	$(O_DIR)/srcs/vm/vm_destroy.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_memfill.o \
	$(O_DIR)/srcs/ui/ui_init.o $(O_DIR)/srcs/ui/key_handler.o \
	$(O_DIR)/libft/ft_printf/exec_format.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_base/ft_abs.o \
	$(O_DIR)/srcs/vm_loader/load_vm.o $(O_DIR)/srcs/vm_exec/operations/st.o \
	$(O_DIR)/srcs/instr_loader/load_instr.o \
	$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/srcs/vm_exec/get_values.o $(O_DIR)/libft/ft_out/ft_write_nchar.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_out/ft_putpad.o \
	$(O_DIR)/libft/ft_list/ft_listremove.o \
	$(O_DIR)/srcs/vm_exec/operations/add.o \
	$(O_DIR)/libft/ft_printf/formats/int.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
	$(O_DIR)/srcs/cor_loader/cor_destroy.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_out/ft_str_out.o

disass: $(O_DIR)/srcs/corewar_config/op.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_subnext.o \
	$(O_DIR)/libft/ft_file/open.o $(O_DIR)/libft/ft_argv/arg.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o $(O_DIR)/libft/ft_base/ft_nanoclock.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/libft/ft_base/ft_memdup.o $(O_DIR)/srcs/instr_loader/load_instr.o \
	$(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_argv/opt.o $(O_DIR)/libft/ft_out/ft_putint.o \
	$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_base/ft_memmove.o \
	$(O_DIR)/libft/ft_out/ft_str_out.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_printf/ft_logf.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o $(O_DIR)/libft/ft_base/ft_bzero.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_base/ft_bitset.o \
	$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_base/ft_rand.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_printf/exec_format.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_base/ft_assert.o $(O_DIR)/libft/ft_printf/ft_putf.o \
	$(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_printf/formats/int.o $(O_DIR)/libft/ft_base/ft_emalloc.o \
	$(O_DIR)/libft/ft_out/ft_putpad.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
	$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/srcs/cor_loader/cor_destroy.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_out/ft_putendl.o \
	$(O_DIR)/srcs/disass/main.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/srcs/disass/print_cor.o \
	$(O_DIR)/libft/ft_out/ft_putsub.o $(O_DIR)/srcs/cor_loader/load_cor.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_strlen.o \
	$(O_DIR)/libft/ft_base/ft_subfind.o $(O_DIR)/libft/ft_base/ft_escape.o

# module asm
$(O_DIR)/srcs/asm/compile.o: srcs/asm/compile.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file/public/file.h libft/ft_file_in/public/file_in.h \
	libft/ft_file_out/public/file_out.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm/p_asm.h \
	srcs/asm/parse_params.h srcs/asm_bytecode/public/asm_bytecode.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/public/asm_parser.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm/debug.o: srcs/asm/debug.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm/main.o: srcs/asm/main.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm/p_asm.h \
	srcs/asm/parse_params.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm/parse_params.o: srcs/asm/parse_params.c \
	libft/ft_argv/public/argv.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_path/public/path.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/asm/parse_params.h

$(O_DIR)/srcs/asm/compile.o $(O_DIR)/srcs/asm/debug.o $(O_DIR)/srcs/asm/main.o \
$(O_DIR)/srcs/asm/parse_params.o: INCLUDE_FLAGS += -Isrcs/asm

# module asm_bytecode
$(O_DIR)/srcs/asm_bytecode/asm_bytecode.o: srcs/asm_bytecode/asm_bytecode.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_set/public/set.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_bytecode/p_asm_bytecode.h srcs/asm_bytecode/public/asm_bytecode.h \
	srcs/asm_data/public/asm_data.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_bytecode/asm_header.o: srcs/asm_bytecode/asm_header.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_bytecode/p_asm_bytecode.h \
	srcs/asm_bytecode/public/asm_bytecode.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h srcs/utils/utils.h
$(O_DIR)/srcs/asm_bytecode/bcode_gen.o: srcs/asm_bytecode/bcode_gen.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_bytecode/p_asm_bytecode.h \
	srcs/asm_bytecode/public/asm_bytecode.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_bytecode/bcode_gen_args.o: \
	srcs/asm_bytecode/bcode_gen_args.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_set/public/set.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_bytecode/p_asm_bytecode.h srcs/asm_bytecode/public/asm_bytecode.h \
	srcs/asm_data/public/asm_data.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_bytecode/labels_ref.o: srcs/asm_bytecode/labels_ref.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_bytecode/p_asm_bytecode.h \
	srcs/asm_bytecode/public/asm_bytecode.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h srcs/utils/utils.h
$(O_DIR)/srcs/asm_bytecode/utils.o: srcs/asm_bytecode/utils.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_bytecode/p_asm_bytecode.h \
	srcs/asm_bytecode/public/asm_bytecode.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h

$(O_DIR)/srcs/asm_bytecode/asm_bytecode.o \
$(O_DIR)/srcs/asm_bytecode/asm_header.o $(O_DIR)/srcs/asm_bytecode/bcode_gen.o \
$(O_DIR)/srcs/asm_bytecode/bcode_gen_args.o \
$(O_DIR)/srcs/asm_bytecode/labels_ref.o $(O_DIR)/srcs/asm_bytecode/utils.o: \
	INCLUDE_FLAGS += -Isrcs/asm_bytecode

# module asm_data
$(O_DIR)/srcs/asm_data/asm_destroy.o: srcs/asm_data/asm_destroy.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_data/asm_label_cmp.o: srcs/asm_data/asm_label_cmp.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_data/public/asm_data.h \
	srcs/corewar_config/public/op.h

# module asm_parser
$(O_DIR)/srcs/asm_parser/check_instr.o: srcs/asm_parser/check_instr.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/check_labels.o: srcs/asm_parser/check_labels.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_asm.o: srcs/asm_parser/parse_asm.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_comment.o: srcs/asm_parser/parse_comment.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_instr.o: srcs/asm_parser/parse_instr.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_instr_arg.o: srcs/asm_parser/parse_instr_arg.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_label_or_instr.o: \
	srcs/asm_parser/parse_label_or_instr.c libft/ft_base/public/libft.h \
	libft/ft_bst/public/ft_bst.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_set/public/set.h libft/ft_tokenizer/public/tokenizer.h \
	libft/ft_vector/public/ft_vector.h srcs/asm_data/public/asm_data.h \
	srcs/asm_parser/p_asm_parser.h srcs/asm_parser/public/asm_parser.h \
	srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/parse_string.o: srcs/asm_parser/parse_string.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h
$(O_DIR)/srcs/asm_parser/utils.o: srcs/asm_parser/utils.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_tokenizer/public/tokenizer.h libft/ft_vector/public/ft_vector.h \
	srcs/asm_data/public/asm_data.h srcs/asm_parser/p_asm_parser.h \
	srcs/asm_parser/public/asm_parser.h srcs/corewar_config/public/op.h

$(O_DIR)/srcs/asm_parser/check_instr.o $(O_DIR)/srcs/asm_parser/check_labels.o \
$(O_DIR)/srcs/asm_parser/parse_asm.o $(O_DIR)/srcs/asm_parser/parse_comment.o \
$(O_DIR)/srcs/asm_parser/parse_instr.o \
$(O_DIR)/srcs/asm_parser/parse_instr_arg.o \
$(O_DIR)/srcs/asm_parser/parse_label_or_instr.o \
$(O_DIR)/srcs/asm_parser/parse_string.o $(O_DIR)/srcs/asm_parser/utils.o: \
	INCLUDE_FLAGS += -Isrcs/asm_parser

# module cor_loader
$(O_DIR)/srcs/cor_loader/cor_destroy.o: srcs/cor_loader/cor_destroy.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	srcs/cor_loader/public/cor_loader.h
$(O_DIR)/srcs/cor_loader/load_cor.o: srcs/cor_loader/load_cor.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file/public/file.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/cor_loader/public/cor_loader.h \
	srcs/corewar_config/public/op.h srcs/utils/utils.h

# module corewar
$(O_DIR)/srcs/corewar_main/dump_loop.o: srcs/corewar_main/dump_loop.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/corewar_config/public/op.h \
	srcs/corewar_main/main.h srcs/instr/public/instr.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/corewar_main/exec_loop.o: srcs/corewar_main/exec_loop.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/corewar_config/public/op.h \
	srcs/corewar_main/main.h srcs/instr/public/instr.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/corewar_main/main.o: srcs/corewar_main/main.c \
	libft/ft_argv/public/argv.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/corewar_main/main.h srcs/corewar_main/parse_argv.h \
	srcs/debug_ui/public/debug_ui.h srcs/instr/public/instr.h \
	srcs/ui/public/ui.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_loader/public/vm_loader.h
$(O_DIR)/srcs/corewar_main/parse_argv.o: srcs/corewar_main/parse_argv.c \
	libft/ft_argv/public/argv.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/corewar_main/main.h srcs/corewar_main/parse_argv.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_loader/public/vm_loader.h
$(O_DIR)/srcs/corewar_main/parse_argv_opt.o: \
	srcs/corewar_main/parse_argv_opt.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/corewar_main/main.h \
	srcs/corewar_main/parse_argv.h srcs/instr/public/instr.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h \
	srcs/vm_loader/public/vm_loader.h
$(O_DIR)/srcs/corewar_main/parse_tools.o: srcs/corewar_main/parse_tools.c \
	libft/ft_argv/public/argv.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/corewar_main/main.h srcs/corewar_main/parse_argv.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_loader/public/vm_loader.h

$(O_DIR)/srcs/corewar_main/dump_loop.o $(O_DIR)/srcs/corewar_main/exec_loop.o \
$(O_DIR)/srcs/corewar_main/main.o $(O_DIR)/srcs/corewar_main/parse_argv.o \
$(O_DIR)/srcs/corewar_main/parse_argv_opt.o \
$(O_DIR)/srcs/corewar_main/parse_tools.o: INCLUDE_FLAGS += -Isrcs/corewar_main

# module corewar_config
$(O_DIR)/srcs/corewar_config/op.o: srcs/corewar_config/op.c \
	srcs/corewar_config/public/op.h

# module debug_ui
$(O_DIR)/srcs/debug_ui/debug_dump.o: srcs/debug_ui/debug_dump.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/get_next_line/public/get_next_line.h srcs/corewar_config/public/op.h \
	srcs/debug_ui/p_debug_ui.h srcs/debug_ui/public/debug_ui.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/debug_ui/debug_loop.o: srcs/debug_ui/debug_loop.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h \
	libft/get_next_line/public/get_next_line.h srcs/corewar_config/public/op.h \
	srcs/debug_ui/p_debug_ui.h srcs/debug_ui/public/debug_ui.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/public/vm_exec.h

$(O_DIR)/srcs/debug_ui/debug_dump.o $(O_DIR)/srcs/debug_ui/debug_loop.o: \
	INCLUDE_FLAGS += -Isrcs/debug_ui

# module disass
$(O_DIR)/srcs/disass/main.o: srcs/disass/main.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	srcs/cor_loader/public/cor_loader.h srcs/disass/p_disass.h
$(O_DIR)/srcs/disass/print_cor.o: srcs/disass/print_cor.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/cor_loader/public/cor_loader.h \
	srcs/corewar_config/public/op.h srcs/disass/p_disass.h \
	srcs/disass/p_disass_print.h srcs/instr/public/instr.h \
	srcs/instr_loader/public/instr_loader.h

$(O_DIR)/srcs/disass/main.o $(O_DIR)/srcs/disass/print_cor.o: INCLUDE_FLAGS += \
	-Isrcs/disass

# module ft::argv
$(O_DIR)/libft/ft_argv/arg.o: libft/ft_argv/arg.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_argv/opt.o: libft/ft_argv/opt.c libft/ft_argv/public/argv.h \
	libft/ft_base/public/libft.h

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_assert.o: libft/ft_base/ft_assert.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bitset.o: libft/ft_base/ft_bitset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bzero.o: libft/ft_base/ft_bzero.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock.o: libft/ft_base/ft_clock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock_stack.o: libft/ft_base/ft_clock_stack.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_getenv.o: libft/ft_base/ft_getenv.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_is.o: libft/ft_base/ft_is.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_max.o: libft/ft_base/ft_max.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcmp.o: libft/ft_base/ft_memcmp.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcpy.o: libft/ft_base/ft_memcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memdup.o: libft/ft_base/ft_memdup.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memfill.o: libft/ft_base/ft_memfill.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memmove.o: libft/ft_base/ft_memmove.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memrcpy.o: libft/ft_base/ft_memrcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memset.o: libft/ft_base/ft_memset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memstart.o: libft/ft_base/ft_memstart.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memswap.o: libft/ft_base/ft_memswap.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_min.o: libft/ft_base/ft_min.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_nanoclock.o: libft/ft_base/ft_nanoclock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_rand.o: libft/ft_base/ft_rand.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strchri.o: libft/ft_base/ft_strchri.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strlen.o: libft/ft_base/ft_strlen.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_sub.o: libft/ft_base/ft_sub.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subfind.o: libft/ft_base/ft_subfind.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subnext.o: libft/ft_base/ft_subnext.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subto.o: libft/ft_base/ft_subto.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_unescape.o: libft/ft_base/ft_unescape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_widetoa.o: libft/ft_base/ft_widetoa.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrconv.o: libft/ft_base/ft_wstrconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrlen.o: libft/ft_base/ft_wstrlen.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrnconv.o: libft/ft_base/ft_wstrnconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h

# module ft::bst
$(O_DIR)/libft/ft_bst/bst_balance.o: libft/ft_bst/bst_balance.c \
	libft/ft_base/public/libft.h libft/ft_bst/bst_internal.h \
	libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bst_destroy.o: libft/ft_bst/ft_bst_destroy.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstdel.o: libft/ft_bst/ft_bstdel.c \
	libft/ft_base/public/libft.h libft/ft_bst/bst_internal.h \
	libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstget.o: libft/ft_bst/ft_bstget.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstgetall.o: libft/ft_bst/ft_bstgetall.c \
	libft/ft_base/public/libft.h libft/ft_bst/bst_internal.h \
	libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstiter.o: libft/ft_bst/ft_bstiter.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstmax.o: libft/ft_bst/ft_bstmax.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstmin.o: libft/ft_bst/ft_bstmin.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h
$(O_DIR)/libft/ft_bst/ft_bstput.o: libft/ft_bst/ft_bstput.c \
	libft/ft_base/public/libft.h libft/ft_bst/bst_internal.h \
	libft/ft_bst/public/ft_bst.h

$(O_DIR)/libft/ft_bst/bst_balance.o $(O_DIR)/libft/ft_bst/ft_bst_destroy.o \
$(O_DIR)/libft/ft_bst/ft_bstdel.o $(O_DIR)/libft/ft_bst/ft_bstget.o \
$(O_DIR)/libft/ft_bst/ft_bstgetall.o $(O_DIR)/libft/ft_bst/ft_bstiter.o \
$(O_DIR)/libft/ft_bst/ft_bstmax.o $(O_DIR)/libft/ft_bst/ft_bstmin.o \
$(O_DIR)/libft/ft_bst/ft_bstput.o: INCLUDE_FLAGS += -Ilibft/ft_bst

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h

# module ft::file
$(O_DIR)/libft/ft_file/open.o: libft/ft_file/open.c \
	libft/ft_base/public/libft.h libft/ft_file/public/file.h

# module ft::file_in
$(O_DIR)/libft/ft_file_in/file_in.o: libft/ft_file_in/file_in.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file_in/public/file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_file_in/file_in_open.o: libft/ft_file_in/file_in_open.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file/public/file.h libft/ft_file_in/public/file_in.h \
	libft/ft_in/public/ft_in.h

# module ft::file_out
$(O_DIR)/libft/ft_file_out/file_out.o: libft/ft_file_out/file_out.c \
	libft/ft_base/public/libft.h libft/ft_file/public/file.h \
	libft/ft_file_out/public/file_out.h libft/ft_out/public/ft_out.h

# module ft::get_next_line
$(O_DIR)/libft/get_next_line/get_next_line.o: \
	libft/get_next_line/get_next_line.c libft/ft_base/public/libft.h \
	libft/get_next_line/gnl_internal.h \
	libft/get_next_line/public/get_next_line.h

$(O_DIR)/libft/get_next_line/get_next_line.o: INCLUDE_FLAGS += \
	-Ilibft/get_next_line

# module ft::hmap
$(O_DIR)/libft/ft_hmap/ft_djb2.o: libft/ft_hmap/ft_djb2.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o: libft/ft_hmap/ft_hmapdatas.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o: libft/ft_hmap/ft_hmapdestroy.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapget.o: libft/ft_hmap/ft_hmapget.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o: libft/ft_hmap/ft_hmapkeys.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o: libft/ft_hmap/ft_hmapnew.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapput.o: libft/ft_hmap/ft_hmapput.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o: libft/ft_hmap/ft_hmapputp.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o: libft/ft_hmap/ft_hmaprem.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/hmap_puth.o: libft/ft_hmap/hmap_puth.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h

$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o $(O_DIR)/libft/ft_hmap/ft_hmapget.o \
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o $(O_DIR)/libft/ft_hmap/ft_hmapnew.o \
$(O_DIR)/libft/ft_hmap/ft_hmapput.o $(O_DIR)/libft/ft_hmap/ft_hmapputp.o \
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o $(O_DIR)/libft/ft_hmap/hmap_puth.o: \
	INCLUDE_FLAGS += -Ilibft/ft_hmap

# module ft::in
$(O_DIR)/libft/ft_in/ft_in_refresh.o: libft/ft_in/ft_in_refresh.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_read.o: libft/ft_in/ft_read.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_readto.o: libft/ft_in/ft_readto.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h

# module ft::list
$(O_DIR)/libft/ft_list/ft_listadd.o: libft/ft_list/ft_listadd.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listremove.o: libft/ft_list/ft_listremove.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listsort.o: libft/ft_list/ft_listsort.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h

# module ft::out
$(O_DIR)/libft/ft_out/ft_putchar.o: libft/ft_out/ft_putchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putendl.o: libft/ft_out/ft_putendl.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putfloat.o: libft/ft_out/ft_putfloat.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putint.o: libft/ft_out/ft_putint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putnchar.o: libft/ft_out/ft_putnchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putpad.o: libft/ft_out/ft_putpad.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putstr.o: libft/ft_out/ft_putstr.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putsub.o: libft/ft_out/ft_putsub.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putuint.o: libft/ft_out/ft_putuint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_str_out.o: libft/ft_out/ft_str_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h
$(O_DIR)/libft/ft_out/ft_write.o: libft/ft_out/ft_write.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_char.o: libft/ft_out/ft_write_char.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_nchar.o: libft/ft_out/ft_write_nchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/out_formats.o: libft/ft_out/out_formats.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h

$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o: \
	INCLUDE_FLAGS += -Ilibft/ft_out

# module ft::path
$(O_DIR)/libft/ft_path/path.o: libft/ft_path/path.c \
	libft/ft_base/public/libft.h libft/ft_path/public/path.h

# module ft::printf
$(O_DIR)/libft/ft_printf/args_utils.o: libft/ft_printf/args_utils.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_format.o: libft/ft_printf/exec_format.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_subformat.o: libft/ft_printf/exec_subformat.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_out/public/ft_str_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/char.o: libft/ft_printf/formats/char.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/int.o: libft/ft_printf/formats/int.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/misc.o: libft/ft_printf/formats/misc.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/str.o: libft/ft_printf/formats/str.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_aprintf.o: libft/ft_printf/ft_aprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_logf.o: libft/ft_printf/ft_logf.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_out.o: libft/ft_printf/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_putf.o: libft/ft_printf/ft_putf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_vprintf.o: libft/ft_printf/ft_vprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h

$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o: \
	INCLUDE_FLAGS += -Ilibft/ft_printf

# module ft::set
$(O_DIR)/libft/ft_set/first.o: libft/ft_set/first.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/get.o: libft/ft_set/get.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/insert.o: libft/ft_set/insert.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/iter.o: libft/ft_set/iter.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/remove.o: libft/ft_set/remove.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/utils.o: libft/ft_set/utils.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h

$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o: INCLUDE_FLAGS += \
	-Ilibft/ft_set

# module ft::tokenizer
$(O_DIR)/libft/ft_tokenizer/ft_token_map.o: libft/ft_tokenizer/ft_token_map.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_tokenizer/public/tokenizer.h
$(O_DIR)/libft/ft_tokenizer/ft_tokenize.o: libft/ft_tokenizer/ft_tokenize.c \
	libft/ft_base/public/libft.h libft/ft_bst/public/ft_bst.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_tokenizer/public/tokenizer.h

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vpush.o: libft/ft_vector/ft_vpush.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vspan.o: libft/ft_vector/ft_vspan.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h

# module instr

# module instr_loader
$(O_DIR)/srcs/instr_loader/load_instr.o: srcs/instr_loader/load_instr.c \
	libft/ft_base/public/libft.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/instr_loader/public/instr_loader.h

# module ui
$(O_DIR)/srcs/ui/key_handler.o: srcs/ui/key_handler.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/ui/p_ui.h srcs/ui/public/ui.h \
	srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/listeners/on_aff.o: srcs/ui/listeners/on_aff.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/ui/p_ui.h srcs/ui/public/ui.h \
	srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/listeners/on_write.o: srcs/ui/listeners/on_write.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h srcs/ui/p_ui.h \
	srcs/ui/public/ui.h srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/ui.o: srcs/ui/ui.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/ui/p_ui.h srcs/ui/public/ui.h \
	srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/ui/ui_arena/arena_update.o: srcs/ui/ui_arena/arena_update.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h \
	srcs/ui/public/ui.h srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_utils.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/ui_arena/w_arena.o: srcs/ui/ui_arena/w_arena.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h srcs/ui/p_ui.h \
	srcs/ui/public/ui.h srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/ui_init.o: srcs/ui/ui_init.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	libft/ft_vector/public/ft_vector.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/ui/p_ui.h srcs/ui/public/ui.h \
	srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/ui_log/w_log.o: srcs/ui/ui_log/w_log.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h srcs/ui/p_ui.h \
	srcs/ui/public/ui.h srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/ui/ui_panel/w_panel.o: srcs/ui/ui_panel/w_panel.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h srcs/ui/p_ui.h \
	srcs/ui/public/ui.h srcs/ui/ui_arena/ui_arena.h srcs/ui/ui_log/ui_log.h \
	srcs/ui/ui_panel/ui_panel.h srcs/ui/ui_utils.h srcs/vm/public/player.h \
	srcs/vm/public/process.h srcs/vm/public/vm.h

$(O_DIR)/srcs/ui/key_handler.o $(O_DIR)/srcs/ui/listeners/on_aff.o \
$(O_DIR)/srcs/ui/listeners/on_write.o $(O_DIR)/srcs/ui/ui.o \
$(O_DIR)/srcs/ui/ui_arena/arena_update.o $(O_DIR)/srcs/ui/ui_arena/w_arena.o \
$(O_DIR)/srcs/ui/ui_init.o $(O_DIR)/srcs/ui/ui_log/w_log.o \
$(O_DIR)/srcs/ui/ui_panel/w_panel.o: INCLUDE_FLAGS += -Isrcs/ui \
	-Isrcs/ui/ui_arena -Isrcs/ui/ui_panel -Isrcs/ui/ui_log

# module utils

# module vm
$(O_DIR)/srcs/vm/vm_access.o: srcs/vm/vm_access.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h
$(O_DIR)/srcs/vm/vm_destroy.o: srcs/vm/vm_destroy.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h
$(O_DIR)/srcs/vm/vm_start.o: srcs/vm/vm_start.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_list/public/ft_list.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h

# module vm_exec
$(O_DIR)/srcs/vm_exec/exec_op.o: srcs/vm_exec/exec_op.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/instr_loader/public/instr_loader.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h \
	srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/get_values.o: srcs/vm_exec/get_values.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/add.o: srcs/vm_exec/operations/add.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/aff.o: srcs/vm_exec/operations/aff.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/and.o: srcs/vm_exec/operations/and.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/fork.o: srcs/vm_exec/operations/fork.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/ld.o: srcs/vm_exec/operations/ld.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/ldi.o: srcs/vm_exec/operations/ldi.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/live.o: srcs/vm_exec/operations/live.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/lld.o: srcs/vm_exec/operations/lld.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/lldi.o: srcs/vm_exec/operations/lldi.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/or.o: srcs/vm_exec/operations/or.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/st.o: srcs/vm_exec/operations/st.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/sti.o: srcs/vm_exec/operations/sti.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/sub.o: srcs/vm_exec/operations/sub.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/xor.o: srcs/vm_exec/operations/xor.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/operations/zjmp.o: srcs/vm_exec/operations/zjmp.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/vm_check.o: srcs/vm_exec/vm_check.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h
$(O_DIR)/srcs/vm_exec/vm_exec.o: srcs/vm_exec/vm_exec.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_exec/p_vm_exec.h srcs/vm_exec/public/vm_exec.h

$(O_DIR)/srcs/vm_exec/exec_op.o $(O_DIR)/srcs/vm_exec/get_values.o \
$(O_DIR)/srcs/vm_exec/operations/add.o $(O_DIR)/srcs/vm_exec/operations/aff.o \
$(O_DIR)/srcs/vm_exec/operations/and.o $(O_DIR)/srcs/vm_exec/operations/fork.o \
$(O_DIR)/srcs/vm_exec/operations/ld.o $(O_DIR)/srcs/vm_exec/operations/ldi.o \
$(O_DIR)/srcs/vm_exec/operations/live.o $(O_DIR)/srcs/vm_exec/operations/lld.o \
$(O_DIR)/srcs/vm_exec/operations/lldi.o $(O_DIR)/srcs/vm_exec/operations/or.o \
$(O_DIR)/srcs/vm_exec/operations/st.o $(O_DIR)/srcs/vm_exec/operations/sti.o \
$(O_DIR)/srcs/vm_exec/operations/sub.o $(O_DIR)/srcs/vm_exec/operations/xor.o \
$(O_DIR)/srcs/vm_exec/operations/zjmp.o $(O_DIR)/srcs/vm_exec/vm_check.o \
$(O_DIR)/srcs/vm_exec/vm_exec.o: INCLUDE_FLAGS += -Isrcs/vm_exec

# module vm_loader
$(O_DIR)/srcs/vm_loader/load_vm.o: srcs/vm_loader/load_vm.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	srcs/cor_loader/public/cor_loader.h srcs/corewar_config/public/op.h \
	srcs/instr/public/instr.h srcs/vm/public/player.h srcs/vm/public/process.h \
	srcs/vm/public/vm.h srcs/vm_loader/public/vm_loader.h
$(O_DIR)/srcs/vm_loader/misc.o: srcs/vm_loader/misc.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/corewar_config/public/op.h srcs/instr/public/instr.h \
	srcs/vm/public/player.h srcs/vm/public/process.h srcs/vm/public/vm.h \
	srcs/vm_loader/public/vm_loader.h

# public links
$(O_DIR)/_public/asm_bytecode.h: srcs/asm_bytecode/public/asm_bytecode.h
$(O_DIR)/_public/asm_data.h: srcs/asm_data/public/asm_data.h
$(O_DIR)/_public/asm_parser.h: srcs/asm_parser/public/asm_parser.h
$(O_DIR)/_public/cor_loader.h: srcs/cor_loader/public/cor_loader.h
$(O_DIR)/_public/debug_ui.h: srcs/debug_ui/public/debug_ui.h
$(O_DIR)/_public/ft/argv.h: libft/ft_argv/public/argv.h
$(O_DIR)/_public/ft/file.h: libft/ft_file/public/file.h
$(O_DIR)/_public/ft/file_in.h: libft/ft_file_in/public/file_in.h
$(O_DIR)/_public/ft/file_out.h: libft/ft_file_out/public/file_out.h
$(O_DIR)/_public/ft/ft_bst.h: libft/ft_bst/public/ft_bst.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_dstr.h: libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/_public/ft/ft_hmap.h: libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/_public/ft/ft_in.h: libft/ft_in/public/ft_in.h
$(O_DIR)/_public/ft/ft_list.h: libft/ft_list/public/ft_list.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/get_next_line.h: \
libft/get_next_line/public/get_next_line.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/path.h: libft/ft_path/public/path.h
$(O_DIR)/_public/ft/set.h: libft/ft_set/public/set.h
$(O_DIR)/_public/ft/tokenizer.h: libft/ft_tokenizer/public/tokenizer.h
$(O_DIR)/_public/instr.h: srcs/instr/public/instr.h
$(O_DIR)/_public/instr_loader.h: srcs/instr_loader/public/instr_loader.h
$(O_DIR)/_public/op.h: srcs/corewar_config/public/op.h
$(O_DIR)/_public/player.h: srcs/vm/public/player.h
$(O_DIR)/_public/process.h: srcs/vm/public/process.h
$(O_DIR)/_public/ui.h: srcs/ui/public/ui.h
$(O_DIR)/_public/utils.h: srcs/utils/utils.h
$(O_DIR)/_public/vm.h: srcs/vm/public/vm.h
$(O_DIR)/_public/vm_exec.h: srcs/vm_exec/public/vm_exec.h
$(O_DIR)/_public/vm_loader.h: srcs/vm_loader/public/vm_loader.h
