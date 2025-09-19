`2025-09-13_17h00`
- Tôi giao tiếp với MKE-M15 không được. Điện thoại kết nối Bluetooth với mạch thành công nhưng nhấn nút trên Gamepad thì không trả về kết quả đã nhấn phím trên Serial Monitor

`2025-09-14`
- 17h00
    + Tôi chèn code tăng tốc - tiến phía trước vào "lệnh UP" thành công --> Động cơ phải trên ban đầu không chạy ở chu kỳ PWM thấp
    + Tôi dùng "lệnh X" để dừng động cơ --> Vấn đề xảy ra: Phải chạy xong chương trình tăng tốc thì xe mới dừng

- 17h20
    - Lệnh UP = điều khiển xe đi thẳng. Nhưng xe đi hướng sang phải do động cơ phải trước quay chậm --> Thử giảm tốc độ đến ngưỡng 2 bên bằng nhau. (tương tự với Lệnh DOWN)
        - 75%: Vẫn đi sang phải
        - 60%: vẫn đi sang phải nhẹ --> Chọn
        - 50%: Tiến phải ít hơn hẳn, động cơ bắt đầu kêu
    - Lệnh LEFT = điều khiển xe tiến trái. Nhưng xe đi tiến trái rất chậm do động cơ phải trước quay chậm
        - Thử 25 - 100 (TRÁI - PHẢI): Xe rẽ trái nhanh trong 1 giây đầu
        - Thử 25 - 75: Xe rẽ trái chậm
        - Thử 15 - 100
    - Lệnh RIGHT = điều khiển xe tiến phải. Nhưng xe đi tiến phải còn hơi chậm (100 - 75)
        - Thử 100 - 50

- 17h50
    - Tiến 60 - 60: Chấp nhận được (lệch phải nhẹ)
    - Lùi 75 - 75: OK
    - Tiến phải: 100 - 15: Tốt --> 100 - 25: OK
    - Tiến trái: 15 - 100: Chậm --> 25 - 100: OK nhưng chậm

- 19h15
    - Canh tốc độ 2 bánh thủ công sao cho khi lệnh xe đi tiến thẳng, xe vẫn tiến thẳng
        - Nếu cho 2 bên chạy 100%  thì bên phải như đang chạy bằng 65% của bên trái
        - Thử đi thẳng với 65 - 100
        - Không thử thủ công mà dùng encoder
        https://deepbluembedded.com/arduino-motor-encoder-optical-encoder-interfacing/ --> Code không hoạt động --> Do dùng D11 thay vì D2 có Interupt --> Code chạy
            - Trái trên, 100% = 225RPM (6V)
    - Xe rẽ trái chậm hơn xe rẽ phải vì lý do 2 bên động cơ quay không đều
    - Canh chỉnh lại tốc độ của 2 động cơ
        - 0-255 ADC ~ 0-100%
        - 255 = 100% = 220RPM (Phai)
        - 173 =  68% = 150rpm (Trai)

- 21h30
    - Chốt phương án: 87.5 - 100 (trái - phải) khi xe đi thẳng
    - 100% bên phải khi rẽ trái bị yếu đi nhiều nên xe rẽ trái vẫn chậm dù đã cân bằng tốc độ

`2025-09-15`
- Đảo chiều vỏ xe: 4 vỏ phải cùng chiều để giảm khả năng lệnh cho xe đi thẳng nhưng xe đi chếch sang phải
https://lopxehaitrieu.vn/phan-biet-lop-mot-chieu-va-lop-da-chieu/#1_Lop_1_chieu_la_gi
- Tra mỡ bò vào bánh răng của động cơ và cho động cơ chạy ở tốc độ 35% để bôi trơn đều các bề mặt bánh răng
    - Tạo chương trình test từng động cơ riêng
- Nút vuông = lùi trái, nút tròn = lùi phải
- Thêm tích năng: bật đèn xi nhan khi rẽ trái/phải
    - Thử if-else bằng Serial.print() trước khi test với đèn thật và cuối cùng là test với xe
    - Thử đèn sáng/tắt trước khi thử đèn nhấp nháy

`2025-09-17`
Anh Ngọc khuyên:
- Tôi nên tập trung vào phần code, vì khung xe tôi nhận được chỉ là khung xe cùi bắp (không thể so sánh với khung xe tăng). TÔi không thể chỉnh phần cứng mãi
    - Khắc phục các lỗi hiện có bằng code hoặc tự điều khiển xe đi thẳng trở lại

- Chương trình điều khiển qua Bluetoohth cơ bản
    - Tôi bắt đầu làm thêm các bài tập: bật xi nhan khi xe rẽ, chớp đèn hazard khi xe lùi (dùng kxnTask)
    - Tận dụng 4 nút bấm trên gamepad để thực hiện các chức năng khác của xe: bấm còi, bật đèn, tắt đèn

- Để tái sử dụng chương trình trên các khung xe khác nhau, tôi cần phải viết thư viện. Tôi nên viết theo mẫu thư viện của anh Ngọc, thống nhất dùng chung 1 chuẩn.
    - Ví dụ lệnh xe tiến phía trước thì 2 bên bánh xe phải dùng quay tiến. Đây là quy tắc chung áp dụng cho mọi khung xe, từ xe 4 bánh tới xe bánh xích


- Chương trình xe tránh vật cản
- Chương trình xe dò line


- Dùng thẻ RFID để mở khóa xe
    - Chương trình sẽ tinh gọn khi lòng ghép được thư viện điều khiển xe vào ...

- Sau đó sử dụng thêm mạch cảm biến gia tốc, cảm biến la bàn trên khung xe ... MPU6050 là cảm biến phổ biến, giá rẻ.
    - Tôi mượn về nghiên cứu kỹ (làm theo các chương trình mẫu lắp trên xe theo như trên mạng), sau đó mua và thí nghiệm trên khung xe của Hshop
