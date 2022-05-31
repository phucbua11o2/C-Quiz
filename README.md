# 5. Thi trắc nghiệm : Ta tổ chức các danh sách sau: 
- Danh sách môn học: mảng con trỏ  (MAMH (C15), TENMH).
- Danh sách Lop : danh sách  tuyến tính (MALOP, TENLOP, con trỏ): con trỏ sẻ trỏ đến danh sách sinh viên thuộc lớp đó.
- Danh sách sinh viên : danh sách liên kết đơn (MASV, HO, TEN,  PHAI, password, con trỏ): con trỏ sẽ trỏ đến điểm các môn đã thi trắc nghiệm.
- Danh sách Điểm thi (danh sách liên kết đơn) (Mamh, Diem)
- Danh sách Câu hỏi thi (cây nhị phân tìm kiếm cân bằng với key = Id) (Id, Mă MH, Nội dung, A, B, C, D, Đáp án); trong đó A, B, C, D là 4 chọn lựa tương ứng với nội dung câu hỏi.

Chương trình có các chức năng sau : 
a/ Đăng nhập dựa vào mã sinh viên, password. Nếu tài khoản đăng nhập là GV, pass là GV thì sẽ có toàn quyền .
b/ NhapLop
c/ In ds lớp
d/ Nhập sinh viên của lớp : nhập vào mã lớp trước, sau đó nhập các sinh viên vào lớp đó. 
e/ Nhập môn học: cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của môn học
f/ Nhập câu hỏi thi (Id là số ngẫu nhiên do chương trình tự tạo  )
g/ Thi Trắc nghiệm ( trước khi thi hỏi người thi môn thi, số câu hỏi thi, số phút thi-sau đó lấy ngẫu nhiên các câu hỏi trong danh sách câu hỏi thi của môn; 
h/ In chi tiết các câu hỏi đã thi 1 môn học của  1 sinh viên, 
i/ In bảng điểm thi trắc nghiệm môn học của 1 lớp (nếu có sinh viên chưa thi thì ghi “Chưa thi”.
Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện làm dữ liệu bị sai. Sinh viên có thể tự thiết kế thêm danh sách để đáp ứng yêu cầu của đề tài.

-Login screen
![image](https://user-images.githubusercontent.com/64189668/171084314-4da60b80-4a31-47ef-b11f-15c3cb38862a.png)
-Manager screen
![image](https://user-images.githubusercontent.com/64189668/171084466-ab59ccfd-d1e3-4ee0-ba5c-4bd30f4fd92b.png)
Class manager screen
![image](https://user-images.githubusercontent.com/64189668/171084533-c369d433-fad0-4cad-b785-8aae6bb19b22.png)
Student manager screen
![image](https://user-images.githubusercontent.com/64189668/171084601-6f321a07-fbfc-4e18-a033-25955737826c.png)
Subject management screen
![image](https://user-images.githubusercontent.com/64189668/171084651-12a2f4e5-bbb6-45ff-818d-059834741e3e.png)
Question management screen
![image](https://user-images.githubusercontent.com/64189668/171084734-03c65b99-5cd4-418e-880f-84a9eb901d04.png)
Point management screen
![image](https://user-images.githubusercontent.com/64189668/171084792-48b6ba55-2efc-4b85-a2c1-2dd1799e8e4f.png)
Exam screen
![image](https://user-images.githubusercontent.com/64189668/171084835-369a450d-f1ab-42d4-a935-b0c539791e50.png)
-Exam student screen
![image](https://user-images.githubusercontent.com/64189668/171084967-6a8a089a-7e1a-42f5-b53e-ce5bc040184b.png)
