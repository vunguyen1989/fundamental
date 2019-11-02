interface DBConnection {
    void connect();
}
 
class OracleConnection implements DBConnection {
    @Override
    public void connect() {
        System.out.println("Oracle connected");
    }
}
 
class MySQLConnection implements DBConnection {
    @Override
    public void connect() {
        System.out.println("MySQL connected");
    }
}
 
class PostgreSQLConnection implements DBConnection {
    @Override
    public void connect() {
        System.out.println("PostgreSQL connected");
    }
}
 
class DatabaseConfig {
    private DBConnection dbConnection;
 
    public DatabaseConfig(DBConnection dbConnection) {
        this.dbConnection = dbConnection;
        this.dbConnection.connect();
    }
 
    public DBConnection getConnection() {
        return this.dbConnection;
    }
}
 
class DIPExample {
 
    public static void main(String[] args) {
        DBConnection conn = new OracleConnection();
        DatabaseConfig config = new DatabaseConfig(conn);
    }
}

/*
    Như bạn thấy, các module của chúng ta không phụ thuộc vào nhau.
    Việc thay đổi code của một module này không ảnh hưởng đến các module còn lại. 
    Nếu muốn hỗ trợ thêm SQLServer chỉ việc tạo thêm class mới, implement từ DbConnection. 
    Nếu muốn đổi kết nối sang Oracle chỉ việc thay đổi trong config, …
*/

/* DIP
    Các module cấp cao không nên phụ thuộc vào các modules cấp thấp. Cả 2 nên phụ thuộc vào abstraction.
    Interface (abstraction) không nên phụ thuộc vào chi tiết, mà ngược lại. ( Các class giao tiếp với nhau thông qua interface, không phải thông qua implementation.)
    
    "High-level modules should not depend on low-level modules. Both should depend on abstractions.
    Abstractions should not depend upon details. Details should depend upon abstractions."
*/