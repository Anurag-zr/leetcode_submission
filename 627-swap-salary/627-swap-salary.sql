# Write your MySQL query statement below
update salary
set sex =
    case sex
    when "m" then "f"
    else "m"
    end;

# or use this

# update salary
# set sex = if(sex="m","f","m");