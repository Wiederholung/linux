#!/bin/bash

# 检查参数
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

directory="$1"

# 检查目录是否存在且可访问
if [ ! -d "$directory" ] || [ ! -r "$directory" ]; then
    echo "Error: Directory '$directory' does not exist or is not accessible"
    exit 1
fi

# 进入目标目录
cd "$directory" || exit 1

# 获取所有文件并排序（不包括子目录）
files=($(find . -maxdepth 1 -type f -not -name ".*" -printf "%f\n" | sort -f))

# 计数器
count=1

# 处理每个文件
for file in "${files[@]}"; do
    # 生成新文件名（3位数字编号）
    new_name=$(printf "%03d_%s" "$count" "$file")
    
    # 执行重命名并输出
    if [ "$file" != "$new_name" ]; then
        mv "$file" "$new_name"
        echo "Renaming '$file' -> '$new_name'"
    fi
    
    ((count++))
done

echo "Renaming completed!"