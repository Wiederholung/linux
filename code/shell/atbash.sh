#!/bin/bash

# 检查参数个数
if [ $# -ne 2 ]; then
    echo "Usage: $0 <mode> <text>"
    echo "mode: encode or decode"
    exit 1
fi

mode=$1
text=$2

# 定义字母替换函数
atbash_char() {
    char=$1
    if [[ $char =~ [a-z] ]]; then
        # 获取字母在字母表中的位置(0-25)
        pos=$(printf "%d" "'$char")
        pos=$((pos - 97))
        # 计算替换后的位置
        new_pos=$((25 - pos))
        # 转换回字符
        printf \\$(printf "%o" $((new_pos + 97)))
    else
        echo -n "$char"
    fi
}

# 编码函数
encode() {
    # 转为小写并移除空格
    text=$(echo "$1" | tr '[:upper:]' '[:lower:]' | tr -cd '[a-z0-9]')
    result=""
    
    # 处理每个字符
    for (( i=0; i<${#text}; i++ )); do
        char="${text:$i:1}"
        if [[ $char =~ [0-9] ]]; then
            result+="$char"
        else
            result+=$(atbash_char "$char")
        fi
        
        # 每5个字符添加空格
        if [ $(( (i+1) % 5 )) -eq 0 ] && [ $i -lt $((${#text}-1)) ]; then
            result+=" "
        fi
    done
    
    echo "$result"
}

# 解码函数
decode() {
    # 移除空格
    text=$(echo "$1" | tr -d ' ')
    result=""
    
    # 处理每个字符
    for (( i=0; i<${#text}; i++ )); do
        char="${text:$i:1}"
        if [[ $char =~ [0-9] ]]; then
            result+="$char"
        else
            result+=$(atbash_char "$char")
        fi
    done
    
    echo "$result"
}

# 根据模式执行相应功能
case "$mode" in
    "encode")
        encode "$text"
        ;;
    "decode")
        decode "$text"
        ;;
    *)
        echo "Invalid mode. Use 'encode' or 'decode'"
        exit 1
        ;;
esac