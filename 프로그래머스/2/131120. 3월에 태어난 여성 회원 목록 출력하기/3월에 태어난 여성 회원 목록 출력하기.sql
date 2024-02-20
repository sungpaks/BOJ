-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, gender, date_format(date_of_birth, '%Y-%m-%d') as date_of_birth
from member_profile
where gender = 'W' and tlno is not null and date_format(date_of_birth, '%m') = '03'