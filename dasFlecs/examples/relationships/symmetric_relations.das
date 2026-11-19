options gen2
require flecs/flecs_boost

// Port of flecs examples/c/relationships/symmetric_relations

[export]
def main() {
    var ecs = ecs_init()

    let TradesWith = ecs_tag(ecs, "TradesWith")

    // Register TradesWith as symmetric relationship. Symmetric relationships
    // go both ways, adding (R, B) to A will also add (R, A) to B.
    ecs_add_id(ecs, TradesWith, EcsSymmetric)

    // Create two players
    let player_1 = ecs_new(ecs)
    let player_2 = ecs_new(ecs)

    // Add (TradesWith, player_2) to player_1. This also adds
    // (TradesWith, player_1) to player_2.
    ecs_add_pair(ecs, player_1, TradesWith, player_2)

    // Log platoon of unit
    print("Player 1 trades with Player 2: {ecs_has_pair(ecs, player_1, TradesWith, player_2)}\n")
    print("Player 2 trades with Player 1: {ecs_has_pair(ecs, player_2, TradesWith, player_1)}\n")

    flecs_fini(ecs)
}

// Output:
//  Player 1 trades with Player 2: true
//  Player 2 trades with Player 1: true
