-- 코드를 입력하세요
SELECT DATE_FORMAT(SALES_DATE, "%Y-%m-%d") as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE as onl
WHERE SALES_DATE LIKE "2022-03-%"
UNION ALL
SELECT DATE_FORMAT(SALES_DATE, "%Y-%m-%d") as SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE as off
WHERE SALES_DATE LIKE "2022-03-%"
ORDER BY SALES_DATE, PRODUCT_ID, IFNULL(USER_ID, 0)