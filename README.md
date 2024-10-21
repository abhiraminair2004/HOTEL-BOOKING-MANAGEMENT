## Object-Oriented Design

The Clazire Hotel Booking System is designed using object-oriented programming principles, particularly focusing on **hierarchical inheritance** and **polymorphism**. Here are the key aspects:

### Hierarchical Inheritance

- **Room Class Hierarchy**: The system utilizes a base class, `Room`, from which two derived classes, `NormalRoom` and `LuxuryRoom`, inherit. This structure allows for a clear organization of room types while enabling shared functionality and properties across different room categories.
- **Shared Functionality**: Common features such as room booking details, add-on services, and billing calculations are defined in the base class, reducing code duplication and enhancing maintainability.

### Polymorphism

- **Dynamic Behavior**: Polymorphism is employed to allow the system to handle different types of rooms (Normal and Luxury) through a common interface. The methods in the `Room` class, such as `calculateDiscount()`, `getRoomType()`, and `showOffers()`, are overridden in the derived classes to provide specific behavior tailored to each room type.
- **Flexible Code**: This allows for greater flexibility in extending the system in the future. For example, if a new room type needs to be added, it can easily inherit from the `Room` class and implement its own specific logic without altering the existing codebase.

### Conclusion

By leveraging hierarchical inheritance and polymorphism, the Clazire Hotel Booking System is both robust and adaptable, providing an efficient and user-friendly experience for hotel room booking and management.
