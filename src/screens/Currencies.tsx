import React, { useState } from 'react'
import { FlatList, StyleSheet, Text, View } from "react-native";
import { newRatesPage1, ratesPage1, ratesPage2 } from '../data/currencies';

function Currency ({label, value, odd}: any){
    return(
        <View style={[style.itemContainer, {backgroundColor: odd ? '#ddd' : '#bbb'}]}>
            <Text>{label}</Text>
            <Text>{value}</Text>
        </View>
    )
}



export default function CurrenciesScreen() {
    const [data, setData] = useState(ratesPage1)
    const [loading, setLoading] = useState(false)
    
    const onEndReached = () => {
        setLoading(true)
        setTimeout(() => { //quando viene chiamato aspetta due secondi e carica gli altri dati
            setData(data => [...data, ...ratesPage2]),
            setLoading(false) 
        }, 2000)
    }

    const onRefresh = () => {
        setLoading(true)
        setTimeout(() => {
            setData(newRatesPage1),
            setLoading(false)
        }, 2000)
    }

    return(
        <FlatList 
            data={data}   
            onRefresh={onRefresh}     
            refreshing={loading}
            renderItem={({item, index}) => (
                <Currency label={item.label} value={item.value} odd={index % 2 === 0}/>
            )}
            onEndReached={onEndReached} //onendreached serve a dire quando si arriva alla fine della pagina
        />
    )
}

const style = StyleSheet.create({
    itemContainer: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        padding: 30,
        borderWidth: 1,
        margin: 10,
        backgroundColor: '#ddd',
        borderColor: '#888',
        borderRadius: 25,
        borderWidth: 2
    }
})