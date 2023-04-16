import React from 'react'
import {NavigationContainer} from '@react-navigation/native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import { Button, Text, View } from 'react-native';
import { Colors } from 'react-native/Libraries/NewAppScreen';

const Stack = createNativeStackNavigator();

export default function NavigationStack(){
    return(
        <NavigationContainer>
            <Stack.Navigator 
                screenOptions={{
                    headerStyle: {backgroundColor: 'red'}}} /*in caso volessi togliere l'heeader dovrei fare "headerShown: false" mentre se la volessi ricreare ricrearla da zero posso benissimo ricontrollare la documentazione "https://reactnavigation.org/docs/headers"*/ 
            >
                <Stack.Screen 
                    name="Home"
                    component={HomeScreen}
                    options={{title: "Pagina Principale"}}
                />
                <Stack.Screen 
                    name="Profile"
                    component={ProfileScreen}
                    options={({route}: any) => ({title: "profilo di " + route.params?.name})}
                />
            </Stack.Navigator>
        </NavigationContainer>
    )
}

function HomeScreen({navigation}:any) {
    return(
        <View>
            <Text>HOME</Text>
            <Button title='go to profile' onPress={() => navigation.navigate('Profile', {name: 'Fabrizio'})} />
        </View>
    )
}

function ProfileScreen({navigation, route}:any) {
    return (
        <View>
            <Text>Ciao {route.params.name}</Text>
            <Button title='go back' onPress={() => navigation.goBack()} />
        </View>
    )
}