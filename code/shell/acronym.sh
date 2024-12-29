#!/bin/bash

# 检查是否有输入参数
if [ $# -eq 0 ]; then
    echo "请提供一个短语作为参数"
    exit 1
fi

# 获取输入短语
phrase="$1"

# 使用 tr 将连字符替换为空格，然后用 awk 处理每个单词
# 最后用 tr 转换为大写
echo "$phrase" | tr '-' ' ' | \
awk '{
    result = ""
    for(i=1; i<=NF; i++) {
        # 获取每个单词的第一个字符
        first_char = substr($i,1,1)
        if (first_char ~ /[A-Za-z]/) {
            result = result first_char
        }
    }
    print result
}' | tr '[:lower:]' '[:upper:]'