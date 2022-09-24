# Write your MySQL query statement below
# update salary
# set 
#     case sex
#     when "m" then "f"
#     else "m"
#     end;

update salary
set sex = if(sex="m","f","m");