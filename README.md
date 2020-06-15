# Automatic-power-off-system
ใช้ Sensor ตรวจจับความเคลื่อนไหว โดยนํามาประมวลผล ส่งค่าให้Arduino ควบคุมโดยรีเลย์หรือรีโมทให้เปิดปิดไฟอัตโนมัติได้คนเมื่อมีคนเดินผ่านหรือในห้องที่ติดตั้งอุปกรณ์ จะมีการควบคุมรีเลย์ให้เปิดปิดไฟอัตโนมัติและมีจอ LED แสดงตัวอักษรขึ้นว่าไฟเปิดปิดการเปิดปิดไฟมีเซนเตอร์ตรวจจับและรีโมทควบคุมกดเปิดปิดไฟ เป็นอีกทางเลือกหนึ่งถ้าเราเดินมาแล้วเซนเซอร์อาจตรวจจับไม่ถึง ก็ใช้รีโมทช่วยแทนได้
# ที่มาและความสำคัญ
การเปิดปิดไฟบ้านโดยปกติแล้วต้องเดินไปกดสวิตซ์ด้วยตนเอง พบปัญหาในการที่จะต้องคอยเดินไปเปิดปิดไฟเองเวลาเข้าห้องเวลานอนหรือห้องนั่งเล่นและห้องต่างๆภายในบ้านเนื่องจากสวิตซ์ไฟนั้นอยู่ไกล ทําให้รู้สึกหงุดหงิดหรือลําบากได้ในบางครั้งถ้าไม่สบายก็ยิ่งรู้สึกต้องการพักผ่อน ประโยชน์ของอุปกรณ์ยังช่วยอํานวยความสะดวกไห้ผู้สูงอายุเวลาท่านอยู่บ้านคนเดียวต้องลุกขึ้นมาเปิดปิดไฟเองบ่อยๆช่วยลดอุบัติเหตุได้ซึ่งเป็นปัจจัยที่สําคัญที่จะต้องมีอุปกรณ์ที่ช่วยอํานวยความสะดวกสบายเวลาเปิดปิดไฟ
ด้วยเหตุนี้และในปัจจุบันการควบคุมไฟบ้านยังคงเป็นสวิทซ์อยู่บ้านที่ต้องการความสะดวกสบายถือว่าเป็นสิ่งจําเป็นอย่างหนึ่งเลยที่หลีกเลี่ยงไม่ได้ ในการเปิดปิดไฟ ทําให้ทางผู้จัดทําได้เล็งเห็นการประยุกต์ใช้การควบคุมระบบไฟอัตโนมัติ
# กลุ่มเป้าหมาย
- ผู้สูงอายุ เด็กและคนพิการ 
- ผู้ป่วยที่ต้องลุกมาเปิดปิดไฟเอง 
- บุคคลทั่วไปที่ต้องการระบบเปิดปิดไฟโดยไม่ต้องกดสวิตซ์ภายในบ้าน
# รายละเอียดโปรเจค
## Perception Module
- lnfrared Remote Control
- Motion Detector
# Behavior
- ตรวจจับการเคลื่อนไหวเมื่อมีคนเดินผ่าน หรือใช้รีโมทควบคุม
- Sensor ทำงานแล้วส่งไปยังรีเลย์
- ไฟเปิด/ปิด แล้วแสดงผลบนจอ LCD ขึ้นว่าไฟเปิดหรือปิด
## Manipulation Module
- Relay
- LED
- LCD I2C Display
# โครงสร้างพื้นฐาน
![โครงสร้างพื้นฐาน](https://user-images.githubusercontent.com/61136772/84518864-85d02180-acfb-11ea-98b3-b6a7059ecea9.jpg)
# ระบบการทำงาน
![ระบบการทำงาน01](https://user-images.githubusercontent.com/61136772/84622177-91dbff00-af06-11ea-83a1-77489704c237.jpg)

