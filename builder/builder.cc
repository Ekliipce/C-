#include "builder.hh"

Car Builder::get_car() const
{
    Car new_car = Car();

    new_car.engine_ = get_engine();
    new_car.body_ = get_body();

    for (size_t i = 0; i < 4; i++)
        new_car.wheels_.at(i) = get_wheel();

    return new_car;
}

std::unique_ptr<Wheel> JeepBuilder::get_wheel() const
{
    std::unique_ptr wheel = std::make_unique<Wheel>(22);
    return wheel;
}

std::unique_ptr<Engine> JeepBuilder::get_engine() const
{
    std::unique_ptr engine = std::make_unique<Engine>(400);
    return engine;
}

std::unique_ptr<Body> JeepBuilder::get_body() const
{
    const std::string str = "SUV";
    std::unique_ptr<Body> body = make_unique<Body>(str);
    return body;
}

std::unique_ptr<Wheel> NissanBuilder::get_wheel() const
{
    std::unique_ptr wheel = std::make_unique<Wheel>(16);
    return wheel;
}

std::unique_ptr<Engine> NissanBuilder::get_engine() const
{
    std::unique_ptr engine = std::make_unique<Engine>(85);
    return engine;
}

std::unique_ptr<Body> NissanBuilder::get_body() const
{
    const std::string str = "hatchback";
    std::unique_ptr<Body> body = make_unique<Body>(str);
    return body;
}
