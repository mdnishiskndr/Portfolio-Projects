#!/usr/bin/env python
# coding: utf-8

# # BMI Calculator

# In[8]:


name = input("Enter your name: ")

weight = int(input("Enter your weight in kilograms: "))

height = int(input("Enter your height in centimers: "))

BMI =(weight)/((height/100)*(height/100))

if BMI > 0:
    if(BMI < 18.5):
        print(name + ", You are underweight.")
    elif(BMI <= 24.9):
        print(name + ", You are normal weight.")
    elif(BMI < 29.9):
        print(name + ", You are overweight.")
    elif(BMI < 34.9):
        print(name + ", You are obese.")
    elif(BMI < 39.9):
        print(name + ", You are severely obese.")
    else:
        print(name + ", You are morbidly obese")
else:
    print("Please enter valid inputs")

print(f"Your BMI is: {BMI:}")


# In[ ]:




