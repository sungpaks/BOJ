-- 코드를 입력하세요
SELECT animal_id, name, date_format(convert(datetime, date), '%Y-%m-%d')
from animal_ins
order by animal_id