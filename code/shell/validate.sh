#!/bin/bash

# 删除输入中的空格
input=$(echo "$1" | tr -d ' ')

# 检查输入是否全为数字
if ! [[ "$input" =~ ^[0-9]+$ ]]; then
    echo "Validation Failed"
    exit 1
fi

# Luhn 算法实现
sum=0
length=${#input}

# 从右到左遍历数字
for (( i=length-1; i>=0; i-- )); do
    digit=${input:i:1}
    
    # 如果是偶数位（从右边算起），则加倍
    if (( (length - i) % 2 == 0 )); then
        digit=$((digit * 2))
        # 如果加倍后的数字大于9，则减去9
        if (( digit > 9 )); then
            digit=$((digit - 9))
        fi
    fi
    
    # 累加
    sum=$((sum + digit))
done

# 检查总和是否能被10整除
if (( sum % 10 == 0 )); then
    echo "Validation Passed"
else
    echo "Validation Failed"
fi
