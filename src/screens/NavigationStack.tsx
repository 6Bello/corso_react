import React from 'react'
import {NavigationContainer} from '@react-navigation/native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import { Button, Text, View } from 'react-native';

const Stack = createNativeStackNavigator();

export default function NavigationStack(){
    return(
        <NavigationContainer>
            <Stack.Navigator>
                <Stack.Screen 
                    name="Home"
                    component={HomeScreen}/>
                <Stack.Screen 
                    name="Profile"
                    component={ProfileScreen}/>
            </Stack.Navigator>
        </NavigationContainer>
    )
}

function HomeScreen({navigation}:any) {
    return(
        <View>
            <Text>HOME</Text>
            <Button title='go to profile' onPress={() => navigation.navigate('Profile')} />
        </View>
    )
}

function ProfileScreen({navigation}:any) {
    return (
        <View>
            <Text>PROFILE</Text>
            <Text>bomba</Text>
            <Button title='go back' onPress={() => navigation.goBack()} />
        </View>
    )
}