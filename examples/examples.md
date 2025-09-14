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