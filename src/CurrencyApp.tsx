import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { Text, View } from 'react-native';
import CurrenciesScreen from './screens/Currencies';
import ConverterScreen from './screens/Converter';
import Icon from 'react-native-vector-icons/FontAwesome';

const Tab = createBottomTabNavigator();

function TabBarIconRefresh({size, color}:any) {
  return <Icon name="refresh" size={size} color={color}/>
} 
function TabBarIconEuro({size, color}:any) {
  return <Icon name="euro" size={size} color={color}/>
} 

export default function CurrencyApp () {

    return (
        <NavigationContainer>
            <Tab.Navigator>
                <Tab.Screen 
                  name="Currencies"
                  component={CurrenciesScreen}
                  options={{
                    tabBarIcon: ({size, color}: any) => (
                    <TabBarIconEuro color={color} size={size}/>
                    ),}}
                />
                <Tab.Screen 
                  name="Converter"
                  component={ConverterScreen}
                  options={{
                    tabBarIcon: ({size, color}: any) => (
                      <TabBarIconRefresh color={color} size={size}/>
                    )
                  }}
                />
            </Tab.Navigator>
        </NavigationContainer>
    ) //comment
}