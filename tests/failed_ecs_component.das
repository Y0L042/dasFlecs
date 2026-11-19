options gen2

// [ecs_component] rejects fields flecs reflection can't describe (expected compile failure).
expect 20800:1
require flecs/flecs_boost

[ecs_component]
struct BadComponent {
    ptr : int?
    items : array<int>
}

[export]
def main() {
    pass
}
