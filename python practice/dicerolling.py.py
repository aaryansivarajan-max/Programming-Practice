import random
import time

def roll_dice():
    print("\n🎲 ** Welcome to the Dice Roller Program! ** 🎲\n")

    while True:
        input("Press Enter to roll the dice...")
        dice_result = random.randint(1, 6)

        print("\n🎲 Rolling...")
        time.sleep(0.5)

        print("\n🎲 ** Dice Result: {} ** 🎲".format(dice_result))

        if dice_result == 1:
            print("\n😄 Joke: Why was the dice cold? Because it had too many ice cubes!")
        elif dice_result == 6:
            print("\n😂 Joke: What do you call a dice with a six on every face? Perfectly balanced!")
        else:
            print("\n🤔 No joke this time, but keep rolling for more fun!")

        play_again = input("\nDo you want to roll again? (yes/no): ").lower()
        if play_again != 'y':
            print("\n👋 Thank you for rolling with us! Have a great day!")
            break

if __name__ == "__main__":
    roll_dice()
