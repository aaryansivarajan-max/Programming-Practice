# Constants
DATABASE_FILE = "CarShowroomDatabase.txt"


# Function to add a car
def add_car():
    with open(DATABASE_FILE, "a") as file:
        brand = input("Enter the brand: ")
        model = input("Enter the model: ")
        year = input("Enter the year: ")
        price = input("Enter the price: ")

        car_data = brand + "," + model + "," + year + "," + price + "\n"
        file.write(car_data)

    print("Car added successfully!")


# Function to view cars
def view_cars():
    with open(DATABASE_FILE, "r") as file:
        for line in file:
            brand, model, year, price = line.strip().split(',')

            car_info = (
                "Brand: " + brand +
                ", Model: " + model +
                ", Year: " + year +
                ", Price: " + price
            )

            print(car_info)


# Function to search for cars
def search_cars():
    keyword = input("Enter a keyword or number to search for: ")

    with open(DATABASE_FILE, "r") as file:
        found = False

        for line in file:
            brand, model, year, price = line.strip().split(',')

            if keyword in line:
                found = True

                car_info = (
                    "Brand: " + brand +
                    ", Model: " + model +
                    ", Year: " + year +
                    ", Price: " + price
                )

                print(car_info)

        if not found:
            print("No matching cars found.")


# Function to update a car
def update_car():
    car_id = int(input("Enter the car ID to update (1-based index): "))

    with open(DATABASE_FILE, "r") as file:
        lines = file.readlines()

    if 1 <= car_id <= len(lines):

        brand, model, year, price = input(
            "Enter updated brand, model, year, and price separated by commas: "
        ).split(',')

        updated_data = brand + "," + model + "," + year + "," + price + "\n"

        lines[car_id - 1] = updated_data

        with open(DATABASE_FILE, "w") as file:
            file.writelines(lines)

        print("Car details updated successfully!")

    else:
        print("Invalid car ID.")


# Function to delete a car
def delete_car():
    car_id = int(input("Enter the car ID to delete (1-based index): "))

    with open(DATABASE_FILE, "r") as file:
        lines = file.readlines()

    if 1 <= car_id <= len(lines):

        deleted_car = lines.pop(car_id - 1)

        with open(DATABASE_FILE, "w") as file:
            file.writelines(lines)

        print("Car details deleted successfully: " + deleted_car)

    else:
        print("Invalid car ID.")


# Main Program
while True:

    print("===================================")
    print("CARSHOWROOM MANAGEMENT SYSTEM")
    print("===================================")

    print("\nCar Showroom Menu:")
    print("1. Add a car")
    print("2. View cars")
    print("3. Search for cars")
    print("4. Update car details")
    print("5. Delete a car")
    print("6. Exit")

    choice = input("Enter your choice (1-6): ")

    if choice == '1':
        print("=========")
        print("ADD CAR")
        print("=========")
        add_car()

    elif choice == '2':
        print("===========")
        print("VIEW CARS")
        print("===========")
        view_cars()

    elif choice == '3':
        print("===========")
        print("SEARCH CAR")
        print("===========")
        search_cars()

    elif choice == '4':
        print("============")
        print("UPDATE CAR")
        print("============")
        update_car()

    elif choice == '5':
        print("============")
        print("DELETE CAR")
        print("============")
        delete_car()

    elif choice == '6':
        print("Exiting the program. Thank you!")
        break

    else:
        print("Invalid choice. Please select a valid option.")