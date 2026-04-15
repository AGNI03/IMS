#include "userRepo.hpp"
#include "models/User.hpp"


UserRepo::UserRepo(const std::string& uri) {
	client = std::make_unique<mysqlx::Client>(
		uri,
		mysqlx::ClientSettings{
			mysqlx::ClientOption::POOLING, true,
			mysqlx::ClientOption::POOL_MAX_SIZE, std::stoi(std::getenv("CLIENT_POOL_SIZE"))
		}
	);
}

UserRepo& UserRepo::getInstance() {
	static UserRepo instance(std::getenv("DB_URI"));
	return instance;
}

void UserRepo::init() {
	(void)getInstance();
}

User UserRepo::getUserById(const std::string& userId) {

	auto session = getInstance().client->getSession();
	auto schema = session.getSchema(std::getenv("DB_NAME"));
	auto table = schema.getTable(std::getenv("DB_TABLE1"));
	auto result = table.select("*")
		.where("user_id = :userId")
		.bind("userId", userId)
		.execute();
	auto row = result.fetchOne();

	auto user = User();
	user._id = row[0].get<std::string>();
	user.userId = row[1].get<std::string>();
	user.username = row[2].get<std::string>();
	user.password_hash = row[3].get<std::string>();
	user.role = row[4].get<std::string>();
	user.created_at = row[5].get<std::string>();
	
	return user;

}