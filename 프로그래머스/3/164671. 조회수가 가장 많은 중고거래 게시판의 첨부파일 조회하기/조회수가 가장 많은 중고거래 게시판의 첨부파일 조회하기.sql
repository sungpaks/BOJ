-- 코드를 입력하세요
SELECT concat('/home/grep/src/', b.board_id, '/', f.file_id, f.file_name, f.file_ext)
from used_goods_board as b join used_goods_file as f
on b.board_id = f.board_id
where views = (select max(views) from used_goods_board)
order by f.file_id desc