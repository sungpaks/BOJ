-- 코드를 입력하세요
SELECT ins.animal_id, outs.name
from animal_ins ins join animal_outs outs
on ins.animal_id = outs.animal_id
where ins.datetime > outs.datetime
order by ins.datetime