<?php
/**
 * Đề bài: Viết hàm check một mảng có phải mảng tăng dần không
 * @param  array  $numbers một mảng số integer
 * @return boolean true nếu tăng dần, ngược lại thì trả về false
 */
function isAssending($numbers)
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
echo isAssending($numbers)?'TĂNG DẦN':'KHÔNG TĂNG DẦN', PHP_EOL;
