-- 코드를 입력하세요
SELECT BOOK_ID, date_format(PUBLISHED_DATE, '%Y-%m-%d') as published_date from book
where category = '인문' and published_date like '2021-%'
order by published_date