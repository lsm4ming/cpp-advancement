#include <iostream>
#include <hiredis/hiredis.h>

constexpr const char *REDIS_HOST = "127.0.0.1";
constexpr const int REDIS_PORT = 6379;
constexpr const char *REDIS_PASS = "redispass";

int main()
{
    // docker run --name redis -d -p 6379:6379 redis --requirepass redispass
    // 创建一个 Redis 上下文
    redisContext *context = redisConnect(REDIS_HOST, REDIS_PORT);
    if (context == nullptr || context->err)
    {
        if (context)
        {
            std::cerr << "Connection error: " << context->errstr << std::endl;
            redisFree(context);
        }
        else
        {
            std::cerr << "Connection error: can't allocate redis context" << std::endl;
        }
        return 1;
    }

    // 设置密码
    const std::string password = REDIS_PASS; // 替换为你的 Redis 密码
    redisReply *reply = (redisReply *)redisCommand(context, "AUTH %s", password.c_str());
    if (reply == nullptr)
    {
        std::cerr << "Error: " << context->errstr << std::endl;
        redisFree(context);
        return 1;
    }

    // 执行 SET 命令
    redisReply *reply = (redisReply *)redisCommand(context, "SET %s %s", "key", "value");
    if (reply == nullptr)
    {
        std::cerr << "Error: " << context->errstr << std::endl;
        redisFree(context);
        return 1;
    }
    std::cout << "SET command result: " << reply->str << std::endl;
    freeReplyObject(reply);

    // 执行 GET 命令
    reply = (redisReply *)redisCommand(context, "GET %s", "key");
    if (reply == nullptr)
    {
        std::cerr << "Error: " << context->errstr << std::endl;
        redisFree(context);
        return 1;
    }
    std::cout << "GET command result: " << (reply->type == REDIS_REPLY_STRING ? reply->str : "nil") << std::endl;
    freeReplyObject(reply);

    // 释放 Redis 上下文
    redisFree(context);
    return 0;
}