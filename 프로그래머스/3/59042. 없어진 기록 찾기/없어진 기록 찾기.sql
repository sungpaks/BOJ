-- 코드를 입력하세요
SELECT outs.animal_id, outs.name
from animal_outs as outs left outer join animal_ins as ins
on ins.animal_id = outs.animal_id
where isnull(ins.animal_id)