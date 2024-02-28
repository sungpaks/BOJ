-- 코드를 입력하세요
SELECT car_id, car_type, daily_fee, options
from car_rental_company_car
where locate("네비게이션", options) > 0
order by car_id desc