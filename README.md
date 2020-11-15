# DefendPROPTIT
fist game

Thể loại defender
Ý Tưởng : các con quái sẽ di chuyển theo đường đi trên map, người chơi sẽ dùng tiền để mua các con
tướng xạ thủ có tầm bắn, sức sát thương khác nhau( có thể bổ sung thêm sát thương chuẩn vì con
quái có giáp, và các trang bị giúp tăng khả năng xuyên giáp ) mỗi khi con quái chết sẽ được 1 khoản tiền tương ứng v
với lượng máu của con quái đó, quái sẽ có giáp và tốc độ đi chuyển khác nhau, riêng con quái
chúa có nhiều giáp và máu, level càng cao giáp càng trâu máu càng giày và con quái chúa sẽ  có thể
có khả năng hồi máu. để con quái lọt vào thành (trụ sở của PROPTIT) thì trụ sở sẽ mất dần máu
theo lượng máu của con quái đã lọt vào, người chơi sẽ thua khi trụ sở bị hết máu.

Chức năng các file: 
- Intro (chưa hoàn thiện ) load data từ file đồng thời tạo của sổ khi mới vào game.
- Data.cpp chứa toàn bộ đữ liệu dc load lên từ file (phòng việc mỗi lần sinh quái
hoặc tạo xạ thủ lại phải load từ file lên)
- Map.cpp dùng ddeer vẽ map.
- Animation.cpp tạo các hoạt ảnh.
- Bug.cpp class quái với các thuộc tính máu,thanh máu, hoạt ảnh (aniomation) ,giáp, chịu sát thương
tốc độ di chuyển và hướng đi.
- Bullet.cpp class đạn tự động tạo 1 lộ trình cho viên đạn bay từ người bắn đến quái nếu va chạm
vào quái sẽ gây sát thương và quay lại vị trí ban đầu k thì đi hết lộ trình cug quay về vị trí ban đầu.
- Shooter.cpp class có người chơi tự động quay theo hướng quái chạy và chứa class đạn.
