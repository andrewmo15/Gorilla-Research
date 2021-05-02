# Sweet Potato Science

## Improving Captive Gorilla Feeding Habits with a Randomized Automatic Feeder

### Benjamin Seleb, Julia Glaze, Nicholas Isaf, Andrew Mo, Tongshu Yang 

#### Keywords:  
Captive animal welfare, Arduino, Foraging, Food intake regulation,  

## Introduction 

There are huge discrepancies between the foraging tendencies of captive gorillas and wild gorillas. Wild gorillas eat small amounts throughout the day whereas gorillas in captivity experience short feeding times in which a lot of food is given at predictable times. Zoo Atlanta is trying to close this gap by implementing an automatic feeder that can be placed in the enclosure in order to both decrease the predictability of feeding times as well as prolong the time the gorillas spend foraging. GaTech4Wildlife VIP was approached by keepers from Zoo Atlanta to improve the existing design to spread different types of food at random, short intervals. This design also had to be programmable in order to account for changes in the amount of food needed to disperse. 

## Background 

Other attempts to increase the foraging time of captive gorillas have been made in the past. Many of these include increasing the difficulty of reaching the food, such as a study done by Colorado State University in which the gorillas’ food was placed in boxes and bags in order to complicate the process of obtaining the food and therefore increase foraging time [Rooney, Sleeman et al. 1998]. However, few studies have been done involving adding the feeder directly in the enclosure.  

The gorillas at Zoo Atlanta are Western Lowland Gorillas (Gorilla gorilla), a critically endangered species of gorilla native to western equatorial Africa, a region containing both lowland forests and swamps. Their diet consists mainly of the pith, leaves, and shoots of various plants native to the region. They will also consume aquatic herbs in swamps, ants and termites, and fruit depending on the season [Maisels, F. et al., 2018]. In captivity, such as at Zoo Atlanta, Gorillas are fed a diet consisting of hard root vegetables and sweet potatoes, in addition to fruit and other foods. A wild male gorilla will eat around 19 kg of food a day and a female or juvenile around 15 kg. This food is foraged, and wild gorillas spend 50-60% of their time foraging for food [Rothman, Jessica M. et al. 2008]. 

Automated feeders are not a new development, as they have been used in multiple animal-related experiments, but they have not been used for this purpose before. Commercial automatic feeders are widely used for animal research. Many are used as a reward system for the animals being tested, dispensing food for the animals whenever they complete a specific task. Nonetheless, the growing popularity of automated feeding systems in experimental environments has resulted in the development of both open- and closed-source feeding systems. The closed-source systems have been designed for a specific species or experiment to allow for more careful and precise research. Open-source systems have been created to be used with many different animals and experiments. These allow for a more general model whose functionality is easy to understand, whose design is flexible enough to implement more specific features, and whose construction can be completed in a short amount of time. This, in turn, allows researchers from all different fields to easily understand and implement our feeders without needing knowledge in construction or electronics.  

An example of an open-source automatic feeder system is one that is created by Jinook Oh, Riccardo Hofer, and W. Tecumseh Fitch. In their paper titled “An open source automatic feeder for animal experiments,” the trio used laser-cut plexiglass as the main container for an Arduino Uno microcontroller. This automated feeder system was then tested on three different animal species and dispensed three different food types: seeds for pigeons (Columba livia), pellets for cats (Felis catus) and pellets for common marmoset monkeys (Callithrix jacchus). 

This paper describes an open-source automatic feeding system that is first being tested with Western Lowland Gorillas. Making it open-source gives researchers at Zoo Atlanta the opportunity to easily incorporate this automated feeder in their experiments. 

### Wild Gorilla Foraging Behavior 

An assumed daily energy intake graph is given in Figure 1, providing an estimate of how much and how often gorillas eat on a daily basis. This graph is based on assumptions of the gorillas’ environment such as the availability of food, temperature and weather patterns, predator threats, and other factors that influence foraging and feeding. These different factors and their corresponding potential influencers are shown in Table 1 below. This spreadsheet is useful in determining how each factor influences the presented graph in Figure 1.  The distribution for gorillas in the wild includes small but frequent feedings throughout the day, leading to over half of the gorillas time dedicated to finding and eating food. 

### Captive Gorilla Foraging Behavior 

Due to a variety of factors, including logistical and safety issues, it is difficult for zookeepers to emulate a gorilla’s natural feeding habits of captivity. Instead, captive gorillas tend to be fed at specific meal times, leading to an energy intake profile similar to that in Figure 2. The goal of this project is to increase the amount of time captive gorillas spend foraging for food and to eventually merge the result of the graph in Figure 2 to look like that of Figure 1.  

## Section 1: Experiment 

In order to test the effectiveness of the team’s novel feeder device, an extensive study of feeding behavior will have to be made prior to implementation and afterwards (pre-implementation and post-implementation). This study will likely involve the manual observation of gorillas in Zoo Atlanta, in collaboration with the primate team. In similar fashion to the diagram in Figure 2, created by Schwitzer et al., typical daily energy intake must be calculated pre- and post-implementation. As indicated by Table 1, daily energy intake is based on a number of factors besides time spent foraging which should also be considered. Depending on the time available for observation and analysis, and for a primary experiment - it may be necessary to simplify energy intake to be only a factor of foraging time. These results will then be compared to the data in Figure 1, the typical daily energy intake of a wild primate in order to determine whether or not the device is having the intended impact.  

For the results to be comparable, and with direction from keepers from Zoo Atlanta, the current plan is to install one feeder per gorilla in the test enclosure. This may be altered, depending on resources available, as it will be much simpler to work with a single device. Prior to all experiments, it should be decided how many feeders will be used and where they will be mounted. The same number of gorillas should be used throughout.  

A sample experimental procedure is listed below: 

Pre-Implementation Procedure:  
1. Video equipment will be fixed in necessary positions in order to monitor all foraging behavior of the gorillas for the entire day.  
2. At least one observer should be present to take notes of different factors and behaviors that influence energy intake and the time at which they were presented. Binoculars and other assistance devices may be necessary. Ideally, this observer would have a good understanding of gorilla behavior and be able to easily identify all relevant information.  
3. Once the gorillas have been removed from the enclosure for the day, all materials/equipment will be removed.  
4. t is likely that the observer was not able to collect all information. For this reason, the video captured should be reviewed and compared in order to accurately estimate daily energy intake.  
5. This procedure may be repeated as many times as necessary in order to confidently present results.  

Post-Implementation Procedure:  
1. Video equipment will be fixed in necessary positions in order to monitor all foraging behavior of the gorillas for the entire day.  
2. Feeders will be programmed, filled, and installed in the morning while keepers are hiding food in the enclosure as usual.  
3. At least one observer should be present to take notes of different factors and behaviors that influence energy intake and the time at which they were presented. In addition, they should note the times at which automatic feeders dispense food.  
4. Once the gorillas have been removed from the enclosure for the day, all materials/equipment will be removed.  
5. Captured video should be reviewed and compared in order to accurately estimate daily energy intake.  
6. This procedure may be repeated as many times as necessary in order to confidently present results.  
7. Results of the post-implementation experiment should be compared with the results of the pre-implementation experiment to identify any change in daily energy intake, or other discrepancies.  

## Section 2: Feeder Design  

### Sweet Potato Math 
In order to correctly design the automatic feeder, calculations needed to be done to ensure the correct parts are used to account for all the variabilities and requirements associated with this project. These design aspects can be grouped into four parts: (a) the distance the food can be spread from the feeder, (b) the effect of different types of food on the functionality of the device, (c) the effect of the weight of the food on the spinner, and finally, (d) what this means in terms of creating and finalizing the design as well as its operation. 

1. Description of Calculations 

One of the most basic engineering requirements for the automatic feeder is the ability to spread the food a sizable distance to cover as much ground as possible. Therefore, several equations have been derived to estimate this distance based on the angular speed of the spinner. This calculation will be key in deciding the minimum spinner motor’s power rating and speed. To simplify the equations, the calculations are based on a number of assumptions: no air resistance, no friction between the food and the spinner plate, the food is placed at the very edge of the spinner, and the food is spinning at exactly the same speed as the spinner plate before it flies off. This calculated radial distance may also vary depending on a number of factors that will be discussed in the couple next sections. In Figure 3, a schematic of the feeder diagram is provided with some of the important variables used in the calculations defined.  

Equation one Eq(1) seen in provides the derived equation for torque in relation to L. This equation depends on the mass of the sweet potato chunks as well as the height at which the feeder is positioned. Starting with the basic equation shown in Eq(1.a.), the torque is equal to the force the sweet potato cube is thrown out multiplied by both how far the force is acting from the center of the spinning disk as well as the angle at which this force acts. Because the force is assumed to act tangent to the spinner, theta becomes 90 degrees and therefore sin(theta) simply becomes one. This can be seen in equation Eq(1.b.). The radius, r, used here is the radius of the spinner since it is assumed that the sweet potato flies off the spinner once it has reached the end of the spinning disk. The centripetal force equation Eq(1.c.) was used to calculate the force used to launch the food from the spinner. This is equal to the mass of the food multiplied by the velocity at which it is launched squared, and then divided by the radius of the spinner.  

The next feat is to calculate the velocity used in the calculations for the centripetal force. To simplify the calculations, the kinematic equation seen in Eq(1.d.) was used. The first step is to break these equations down into their separate horizontal and vertical components. The first limiting factor that needs to be calculated is the time that it takes the food to hit the ground.  

Using equation Eq(1.e.), the initial vertical velocity is known to be zero, the total distance travelled, delta x, is the height of the spinner disk, h, and the acceleration is known to be the gravitational acceleration, 9.81 m/s. The time was then found to be the square root of two times the height of the spinner disk divided by g. Next, using Eq(1.f.) the horizontal component of velocity was found by using the simple equation of dividing distance per time in which the distance the spinner threw the food was used for the numerator and the time found in the previous section was used for the denominator. This is shown in Eq(1.g.) Finally, all the equations are substituted back into the equation used for torque. This equation is listed as equation Eq(1.h.) and successfully relates the necessary torque of the motor to the distance the food could be spread from the feeder.  

2. Influences of Different Types and Shapes of Food 

As mentioned above, different types of food may also influence the result, as they each have different densities, friction coefficients and aerodynamic properties. The main food type present in this discussion is raw sweet potato since this is determined to be the most difficult of the gorillas diet to work with. Before inserting the gorillas’ food into the bucket, the sweet potatoes will be diced into 8mm cubes. Equation 2,Eq(2), illustrated the maximum distance that the design will need to account for when spreading these cubes. In a study conducted in 2016, cubes in a granular flow were seen to consistently rank lowest in flow rate out of a hopper. This is relevant to our study when dealing with future modifications. Especially if a more efficient or faster flow rate is desired. [Toson, Khanist, et al. 2016]  

Another point to consider in the flow of cubes out of the hopper is the friction between both the cubes themselves and the cubes and the walls of the hopper. Undoubtedly, this will decrease the total amount of food that is able to flow out of the hopper. Research has indicated that the coefficient of friction between sweet potato and galvanized aluminum is about 0.4. [Toson, Khanist, et al 2016]  The internal friction coefficient of sweet potatoes has also been found to be around 0.095 to 0.198 [Finney, Norris et al. 1967]. This information can be used in future calculations by recalibrating the existing models to more closely match what is actually happening. 

3. Effect of Weight on Spread Distance  

Another calculation that is important for the understanding of this device is the angular velocity of the spinning disk. Starting with the basic equation for angular velocity as seen in Eq (3.a.), linear velocity was divided by the radius of the spinning disk. This is the same linear velocity calculated in the first section, the radial distance divided by the time it takes to hit the ground shown in Eq(1.g.). Again, this time has already been calculated in the previous section using simple kinematics seen in Eq (1.e.). Finally, we are left with a function relating the angular speed of the motor to the radial distance the food travels shown in Eq (3). 

Although the derived calculations are known to not be exact, especially with all the assumptions made, one foreseeable discrepancy between the equation’s model and the actual spread radius is the effect of the weight of the food on the spinning disk. The increase in mass placed on the spinner will increase the friction between the disk and the motor and therefore decrease the amount of force the motor can output. This is why, in equation Eq(3), the angular speed is found to be a function of the mass on the spinner. In order to refine this equation, we need to conduct experiments to test exactly where the food lands in comparison to the motor torque. After collecting this data, a graph can be constructed comparing the total mass on the spinner to the spread radius. From this we will be able to construct a line of best fit and finally obtain an equation that best represents this relationship.  

### Design 

The design for the automatic gorilla feeder is shown in Figure 6. It consists of three main sections: a box, a platform with a spinner, and a hopper. This design was chosen for a multitude of reasons, chief of which are that it is based on existing feeders which are known to work and that it is simple and almost all the pieces can be laser cut, allowing for it to be easily created by anyone who desires to use it. The design also allows the feeder to be hung from trees high above the gorillas and out of reach and also allows for a greater dispensing range. 

The box is built out of laser-cut 1/8th in. acrylic and houses all of the hardware components, including the motor, Arduino, and battery. The box also has a cut-out in the front where the LCD User Interface, including buttons, is accessed from. A detailed CAD model of the Box can be seen below Figure 7. The interfaces are tabs, selected for their ease of assembly and ability to self-support. In addition, acrylic glue will still be used to provide a stronger and waterproof connection.  

The top of the Box is a platform on which the spinner (connected to the motor in the box) rests. Four risers connect this bottom platform with a second platform which is attached to the hopper. The risers allow for a gap for the food to be dispensed from. The Hopper is simply a metal bucket with a funnel a hole in the bottom. The hole is covered by a specially-designed gate operated by a servo motor attached to the hopper platform which controls when and for how long food is released.  

A prototype of the design can be seen in Figure 8. Figure 9 shows the inside of the same prototype with electrical components. 

### Requirements  

Below are a variety of requirements that the feeder must meet with an explanation of how the automatic gorilla feeder satisfies them. 

1. Rainproof: All components other than the hopper and spinner are to be made from acrylic, a waterproof material which will keep the motor and circuitry dry in rain.  
2. Durability: Acrylic is a durable material. 
3. Pest (Squirrel) Resistant: A secondary servo motor acts as a gate keeping the hopper opening closed until food is to be dispensed. This prevents squirrels and other pests from being able to access the food. 
4. Large Food Size: The platform which holds the spinner and the platform that holds the hopper are connected by risers which can be adjusted. This allows for a larger clearance for larger food items if need be.  
5. Secured Battery.  
6. Size requirements? How much food do we want to hold  
7. How much does a single gorilla eat per day? One feeder per gorilla  

### Hardware 

#### Electronics Parts List 

The following materials will be used to finish building the electrical side of the automatic feeder: 
1. Arduino Uno R3 
2. Permanent breadboard 
3. Display Module 16x2 Serial Blue Backlight LCD Module 
4. Sunfounder 55g Metal Gear Servo Motor 
5. 6V DC motor from American Hunter Deer Feeder 
6. 3 12 x 12 x 12 mm Momentary Tact Tactile Push Buttons 
7. Potentiometer 
8. 6 220-Ohm resistors 
9. Transistor 
10. Diode 
11. One 9-volt battery with  

#### Schematic 

The assembly and wiring of these materials are shown in the schematic below. As always, it is recommended that short wires are used so that it is cleaner and easier to manipulate during building and testing. The wiring in the schematic, shown in Figure 10, is colored as to easily differentiate between each component’s wiring. All wiring connected to GND. 

### Software 

#### User Interface 

There are three screens that can be accessed by the users. These screens are displayed on an LCD and will change based on whichever one of the 3 momentary push button switches is pressed. The first screen is the home screen, which shows the number of times that the feeder will dispense food and the number of hours that the feeder will stay active. The first screen also allows the user to edit these two settings by pressing the corresponding buttons. The leftmost button allows the user to toggle the number of times that the feeder will dispense food.  The rightmost button allows the user to edit toggle the number of hours that the feeder will be active for. The other two screens will give you the option to increase or decrease the setting, depending on which on the users have selected. The values can be incremented with the leftmost button or decremented with the rightmost button. The diagram below shows a template of what is displayed at each screen. After the two settings are configured, the data is stored within the Arduino Uno microcontroller and will be used to calculate random times during the day that the automatic feeder will dispense food. 

#### Flowchart 

The program begins with instantiating the liquid crystal display object and the servo object. It also declares and assigns all the necessary variables. It proceeds to call the toggleLCD method, where the program waits for a user input of non-negative values for both the times and hours. When nonnegative values are retrieved and stored into the hours and times variables, isHours and isTimes will be set to true. The program then sets the LCD’s backlight to low to save on battery consumption. It finds the next positive random time and waits that much time before spinning the DC motor and the Servo motor for 10 seconds. It will then reset positive to false and continue with the rest of the program.  

#### Testing 

After fabrication of the prototype was completed, the efficiency of each of the spinners was tested in order to determine which would best spread the food in even intervals a sizable distance away. The two spinners tested can be seen in Figure 13.  

In order to test the efficiency of each spinner, the spinner was first connected to the battery pack, causing it to spin. Then, sweet potatoes were dropped onto the spinner, simulating how the sweet potatoes will fall from the servo motor gate. Then, sweet potatoes were counted in different distance intervals: 10 or more feet, 8-10 feet, 6-8 feet, 4-6 feet, 2-4 feet, and 0-2 feet. This data can be found in Table 2.  

During testing, a number of different observations were noted. First, two different power settings are available for the DC battery pack. However, the higher power setting damaged the sweet potatoes, causing the spinner to slice the falling sweet potatoes instead of spreading them. For this reason, the lower power setting will be chosen. Another observation from the testing is the importance of the surface that the sweet potatoes land on. The initial tests were run on a tarp. However, it was noticed that once the potatoes landed on the tarp, they would slide a few inches further than where they landed. This would provide incorrect results, since the gorilla enclosure would have mostly grass. Therefore, the tarp was removed and the remainder of the tests were conducted on grass.  

Based on the result of Table 2, the Pie Graph Figure 14 is constructed. From these results from Pie Graph, it can be noted that the black spinner has a more uniform distribution when compared to the sliver spinner. Because of this, the black spinner was decided for the design.  

Then, the results of the black spinner were extrapolated to simulate how far the feeder would spread if it were instead raised to 40 feet off the ground, as it would be in the enclosure. The result in Table 3 are the resulting data points. Based on the math from the Section 2: Sweet Potato Math, we got the result in the last column of Table 3. 

## Next Steps 

The immediate objective following the Fall 2020 semester is to complete the full assembly of the feeding device and ensure that all the subparts work together to disperse the food correctly and smoothly. The next most important step is to complete the mathematical model of the system to predict the performance of the spinner by creating a regression model. This model should be able to describe how long the spinner takes to disperse an entire bucket of food, how long it takes for the spinner to reach maximum speed, and after the servo motor closes the gate, how the distance that the sweet potatoes are spread, and how long will the spinner take to disperse the rest of the food within the spinner area. These models are also important for determining the total amount of food dispensed per operation, so that programming for different enclosure conditions can be as accurate as possible. 

It is also essential to determine the approximate feeding schedule is necessary dependent on the number of gorillas present in the enclosure, as well as the age and sex of the gorilla. Once all design factors have been defined and tested, a zoo-ready prototype can then be constructed. A manual and fabrication guide should be written to accompany this new device.  

Once the device is implemented into the enclosure, observations of the gorillas before and after the device is installed will determine whether or not this was a successful experiment. This will be conducted through use of an ethogram, which is a list of all the common gorilla behaviors that is used in observation. The major goal of this effort is to increase captive gorilla foraging time to match that of their wild counterparts. If the implemented device is shown to be somewhat successful, the device and feeding schedule may be modified further to improve results.  

Also in the future, as far as electronics and control are concerned, further features can be added to the LCD. As stated in the electronics section, there are only two settings that are available to change: the number of times that the feeder dispenses food and the number of hours that the feeder will operate each day. One setting that can be added into the system is the number male and female Western Lowland Gorillas are in the habitat. Since their diets are different, the feeder can make more precise dispenses depending on the demographic of the gorillas in the habitat. Others can be added to the Arduino code in light of further research. 

Lastly, we must be able to program the Arduino to power off when it is idle and to turn on when it needs to. An Arduino Uno is an extremely difficult microcontroller to power directly with a battery, as there are many internal clock cycles and LEDs that are extremely power-hungry. Therefore, we will be exploring the LowPower library and using their deepSleep() functions as well as internal interrupts that will awaken the Arduino at the appropriate time. As a result, the Arduino will not drain a standard 6V battery in a mere 8 hours and instead last for weeks and possibly years without replacement. 

## References  

Alvarez, M.D., Canet, W. And Fernández, C. (2007), The Effect of Temperature, Geometry, Gap And Surface Friction On Oscillatory Rheological Properties Of Mashed Potatoes. Journal of Food Process Engineering, 30: 267-292. doi:10.1111/j.1745-4530.2007.00120.x

Höhner, D., et al. “A Study on the Influence of Particle Shape on the Mechanical Interactions of Granular Media in a Hopper Using the Discrete Element Method.” Powder Technology, vol. 278, July 2015, pp. 286–305. ScienceDirect, doi:10.1016/j.powtec.2015.02.046. 

J. Oh, R. Hofer, W.T. Fitch, An open source automatic feeder for animal experiments, HardwareX (2016), doi: http://dx.doi.org/10.1016/j.ohx.2016.09.001  

Joykumar Singh, Ngankham, and Ram Krishna Pandey. “Convective Air Drying Characteristics of Sweet Potato Cube (Ipomoea Batatas L.).” Food and Bioproducts Processing, vol. 90, no. 2, Apr. 2012, pp. 317–22. ScienceDirect, doi:10.1016/j.fbp.2011.06.006. 

Maisels, F., Bergl, R.A. & Williamson, E.A. 2018. Gorilla gorilla (amended version of 2016 assessment). The IUCN Red List of Threatened Species 2018: e.T9404A136250858.  

Matthew B. Rooney & Jonathan Sleeman (1998) Effects of Selected Behavioral Enrichment Devices on Behavior of Western Lowland Gorillas (Gorilla gorilla gorilla), Journal of Applied Animal Welfare Science, 1:4, 339-351, DOI: 10.1207/s15327604jaws0104_2 

Rothman, Jessica M., et al. “Nutritional Quality of Gorilla Diets: Consequences of Age, Sex, and Season.” Oecologia, vol. 155, no. 1, 2008, pp. 111–122. JSTOR, www.jstor.org/stable/40213145. Accessed 9 Apr. 2020. 

Schwitzer, C., & Kaumanns, W. (2003). Foraging patterns of free-ranging and captive primates – implications for captive feeding regimes. Retrieved from https://www.researchgate.net/publication/242097036_Foraging_patterns_of_free-ranging_and_captive_primates_-_implications_for_captive_feeding_regimes  

Toson, P., & Khinast, J. (2017). Impulse-Based Dynamics for Studying Quasi-Static Granular Flows: Application to Hopper Emptying of Non-Spherical Particles. doi: https://doi.org/10.1016/j.powtec.2017.03.01  

## Appendices

