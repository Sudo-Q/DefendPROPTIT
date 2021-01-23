# DefendPROPTIT
fist game

Thể loại defend
Ý Tưởng : các con quái sẽ di chuyển theo đường đi trên map, người chơi sẽ dùng tiền để mua các con
tướng xạ thủ có tầm bắn, sức sát thương khác nhau( có sát thương chuẩn vì con
quái có giáp, và các trang bị giúp tăng sát thương cơ bản, sát thương chuẩn, tầm bắn, tốc độ đạn bay ) mỗi khi con quái chết sẽ được 1 khoản tiền tương ứng với
với lượng máu của con quái đó, quái sẽ có giáp và tốc độ đi chuyển khác nhau, riêng con quái
chúa có nhiều giáp và máu, level càng cao giáp càng trâu máu càng dày. để con quái lọt vào thành (trụ sở của PROPTIT) thì trụ sở sẽ mất dần máu
theo lượng máu của con quái đã lọt vào, người chơi sẽ thua khi trụ sở bị hết máu.

Chức năng các file: 
- Intro.cpp tạo của sổ khi mới vào game.
- Data.cpp chứa toàn bộ đữ liệu dc load lên từ file (phòng việc mỗi lần sinh quái
hoặc tạo xạ thủ lại phải load từ file lên)
- Map.cpp dùng để vẽ map.
- Animation.cpp tạo các hoạt ảnh.
- Bug.cpp class quái với các thuộc tính máu,thanh máu, hoạt ảnh (aniomation) ,giáp, chịu sát thương
tốc độ di chuyển và hướng đi.
- Bullet.cpp class đạn tự động tạo 1 lộ trình cho viên đạn bay từ người bắn đến quái nếu va chạm
vào quái sẽ gây sát thương và quay lại vị trí ban đầu k thì đi hết lộ trình cug quay về vị trí ban đầu.
- Shooter.cpp class có người chơi tự động quay theo hướng quái chạy và chứa class đạn.
-outro.cpp class hiển thị điểm của người chơi và kết thúc game, nếu người chơi chọn tiếp tục chơi thì quay lại game ban đầu, làm m
