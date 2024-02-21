-- 코드를 입력하세요
SELECT BOOK_ID, AUTHOR_NAME, date_format(PUBLISHED_DATE, '%Y-%m-%d') as published_date
FROM BOOK as b join AUTHOR as a on b.author_id = a.author_id
where category = "경제"
order by published_date