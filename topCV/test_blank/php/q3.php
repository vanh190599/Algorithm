<?php
/**
 * Đề bài: Kiểm tra một mảng có phải sẽ tăng dần nếu chỉ đổi chỗ 1 cặp số
 * Ví dụ:
 *  1 4 5 9 7 6 ==> true : Vì đổi chỗ số 6 cho số 9 là ok
 *  4 1 5 9 7 6 ==> false : Vì phải đổi chỗ nhiều hơn 2 cặp số
 *  1 2 3 4 5 6 ==> false : Vì đã tăng dần sẵn rồi
 * @param  array  $numbers một mảng số integer
 * @return boolean true nếu thoả mãn yêu cầu, người lại thì false
 */
function check($numbers)
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
echo check($numbers)?'THOẢ MÃN':'KHÔNG THOẢ MÃN', PHP_EOL;
