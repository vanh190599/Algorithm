<?php
/**
 * Đề bài: Kiểm tra số nào được lặp lại nhiều nhất trong mảng
 * @param  array  $numbers một mảng số integer
 * @return integer số được lặp lại nhiều nhất
 */
function getTheMostPopularNumber($numbers)
{
    // TODO: Viết code vào đây

}

// ====================== TEST KẾT QUẢ ====================
// Đọc input, nhập vào 1 dãy số integer cách nhau bởi dấu space ,
$p = fopen('php://stdin', 'r');
echo 'Nhập dãy số cách nhau bởi dấu space: ';
$input = trim(fgets($p));
fclose($p);
$numbers = array_map('intval', explode(' ', $input));
// In kết quả ra màn hình
echo 'Số lặp lại nhiều nhất là: ' . getTheMostPopularNumber($numbers), PHP_EOL;
