# Write your MySQL query statement below

select user_id , count(user_id) as prompt_count, Round(AVG(tokens),2) as avg_tokens 
from prompts
group by user_id
having prompt_count >= 3 and avg_tokens < max(tokens)
order by avg_tokens desc,user_id