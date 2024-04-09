# Coffee Shop☕
Managing orders for a **cafe**. 

**Classes**:

-**OrderInterface** class - it's an interface for the Order class

-**Product** class - an abstract class for the cafe's products

-**Coffee** class - to store details about coffee (type of coffee, size of coffee, price of coffee)

-**FlavouredCoffee** class - to store details about flavored coffee

-**VegetalMilkCoffee** class - to store details about coffee with plant-based milk

-**FlavouredCoffeeWithVegetalMilkCoffee** class - to store details about flavored coffee with plant-based milk (using diamond inheritance)

-**Pastry** class - to store details about a pastry product (type of product, price of product)

-**Tea** class - to store details about tea (type of tea, price of tea)

-**Order** class - is the order class, which inherits a vector of products and the OrderInterface interface

-4 *custom* exception classes: **NegativePriceException**, when setting negative prices for products, **ProductNotFoundException**, when attempting to delete a nonexistent product from the order, **InvalidProductException**, when attempting to add a product to the order that is not of type Coffee, FlavouredCoffee, VegetalMilkCoffee, FlavouredCoffeeWithVegetalMilkCoffee, Pastry, or Tea, **EmptyOrderException**, when the order is empty


# **Functionalities**

-able to add products to the order and delete products from the order

-able to calculate the total of the order

-able to display how much the customer needs to pay

-able to display the order sorted by the price of the products

-able to offer a 15% discount for students

-able to display how many coffees, teas, and pastry products have been sold in total




