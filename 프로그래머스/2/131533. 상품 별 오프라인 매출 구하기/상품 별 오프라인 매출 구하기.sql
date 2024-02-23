-- 코드를 입력하세요
SELECT product_code, price * sum(sales_amount) as sales
from product as p join offline_sale as os
on p.product_id = os.product_id
group by product_code
order by sales desc, product_code