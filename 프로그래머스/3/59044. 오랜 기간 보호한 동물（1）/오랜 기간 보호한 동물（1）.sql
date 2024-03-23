-- 코드를 입력하세요
SELECT ins.name, ins.datetime
FROM ANIMAL_INS ins LEFT JOIN ANIMAL_OUTS outs
ON ins.animal_id = outs.animal_id
WHERE outs.animal_id IS NULL
ORDER BY datetime
LIMIT 3